#include <iostream>
#include <cstring>
using namespace std;

int a[1001], dp[1001][1001];

int f(int left, int right, int n) {
    if (left > right) return 0;

    if (dp[left][right] != 0) { // 이미 계산 한적 있는 경우
        return dp[left][right];
    }

    if (n % 2 == 0) { // 근우 차례 (왼쪽 뽑기 vs 오른쪽 뽑기)
        return dp[left][right] = max(a[left] + f(left + 1, right, n + 1), a[right] + f(left, right - 1, n + 1));
    }
    else {  // 명우 차례
        return dp[left][right] = min(f(left + 1, right, n + 1), f(left, right - 1, n + 1));
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
 
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        cout << f(1, N, 0) << '\n';
        memset(dp, 0, sizeof(dp));  // 초기화
    }
}