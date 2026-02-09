#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<long long> dp(n + 1);

		if (n >= 1) dp[1] = 1;
		if (n >= 2) dp[2] = 1;
		if (n >= 3) dp[3] = 1;
		if (n >= 4) dp[4] = 2;
		if (n >= 5) dp[5] = 2;

		for (int j = 6; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		cout << dp[n] << '\n';
	}
}