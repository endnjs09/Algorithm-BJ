#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;

        vector<int> v(K + 1);
        vector<int> sum(K + 1, 0);
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));

        for (int i = 1; i <= K; i++) {
            cin >> v[i];
            sum[i] = sum[i - 1] + v[i]; // 누적합
        }

        for (int L = 2; L <= K; L++) {  // 길이
            for (int i = 1; i <= K - L + 1; i++) {  // 시작 지점
                int j = i + L - 1; // 끝 지점
                dp[i][j] = INF;    

                for (int m = i; m < j; m++) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + (sum[j] - sum[i - 1]));
                }
            }
        }


        cout << dp[1][K] << "\n";;
    }
}