#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    vector<vector<int>> b(x, vector<int>(y, 0));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> ans(n, vector<int>(y, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < y; k++) {
                ans[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}