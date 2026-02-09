#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	vector<int> v(n + 1);
	vector<int> w(n + 1);

	v[0] = 0, w[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	// 배낭의 용량이 0
	for (int w = 0; w <= k; w++) dp[0][w] = 0;
	// 아무것도 담지 않음

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << dp[n][k];
}