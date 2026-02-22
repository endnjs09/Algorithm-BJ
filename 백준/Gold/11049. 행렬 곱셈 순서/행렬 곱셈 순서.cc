#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> d(N, vector<int>(2));
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= N; i++) dp[i][i] = 0;

    // A1, A2, A3, A4
    for (int L = 1; L < N; L++) {           // 구간 길이 (1~3)
        for (int i = 1; i <= N - L; i++) {  // 시작점 
            int j = i + L;  // 끝 지점

            for (int k = i; k < j; k++) {   // 끊는 지점 A1 x (A2 x A3) >> dp[1][1] + dp[2][3] + d0d1d3
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1][0] * d[k - 1][1] * d[j - 1][1]);
            }
        }
    }

    cout << dp[1][N];
}