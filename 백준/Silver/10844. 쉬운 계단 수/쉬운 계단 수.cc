#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1e9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;	// 길이가 1이면서 i로 끝나는 수 
	}

	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= 9; i++) {
			if (i == 0) dp[k][i] = dp[k - 1][i + 1] % SIZE;				// 길이가 n이면서 끝이 0으로 끝남
			else if (i == 9) dp[k][i] = dp[k - 1][i - 1] % SIZE;		// 길이가 n이면서 끝이 9로 끝남
			else dp[k][i] = (dp[k - 1][i + 1] + dp[k - 1][i - 1]) % SIZE;	// 길이가 n이면서 끝이 i로 끝남
		}
	}

	long long r = 0;
	for (int i = 0; i <= 9; i++) {
		r = (r + dp[n][i]) % SIZE;
	}

	cout << r;
}