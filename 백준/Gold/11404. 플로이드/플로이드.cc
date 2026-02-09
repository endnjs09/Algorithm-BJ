#include <iostream>
#include <vector>
#include <queue>
#define INF 1e8
using namespace std;

int d[101][101];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {              // 거쳐가는 도시
        for (int i = 1; i <= n; i++) {          // 출발
            for (int j = 1; j <= n; j++) {      // 도착
                if (d[i][k] + d[k][j] < d[i][j]) {  // k를 거쳐갔을 때 더 빠르면
                    d[i][j] = d[i][k] + d[k][j];    // 갱신
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }


    for (int i = 0; i < m; i++) {
        int a, b, c;    // 출발, 도착, 비용
        cin >> a >> b >> c;

        d[a][b] = min(d[a][b], c);
    }

    floyd(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] >= INF) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}