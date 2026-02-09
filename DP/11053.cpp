#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}