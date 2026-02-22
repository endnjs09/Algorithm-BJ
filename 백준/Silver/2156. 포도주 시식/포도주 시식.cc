#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp[0] = 0;
    dp[1] = max(0, v[1]);   // 첫번째 잔: 안 마심 vs 마심
    if (n >= 2) {
        dp[2] = max(dp[1], dp[1] + v[2]);   // 두번째 잔: 2번 잔 안 마심(1번만 마심) vs 둘다 마심

        for (int i = 3; i <= n; i++) {
            dp[i] = max({dp[i - 3] + v[i] + v[i - 1], dp[i - 2] + v[i], dp[i - 1]});
            // 1) i번을 2번째 연속 마시는 경우 (i-2번은 마시면 안됨 >> i-3번까지의 최고)
            // 2) i번이 첫번째 잔인 경우 (i-1번은 마시면 안됨 >> i-2번까지의 최고)
            // 3) i번을 안 마시는 경우 (i-1번까지의 최고)
        }
    }

    cout << dp[n];
}