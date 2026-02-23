#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n), dp(k + 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0] = 1;
    for (int m : v) {   // v에서 꺼낸 돈 m (1, 2, 5)
        for (int i = m; i <= k; i++) {
            dp[i] = dp[i] + dp[i - m];
        }
    }

    cout << dp[k];
}