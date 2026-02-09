#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j].second < a[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ans = max(dp[i], ans);
	}

	cout << n - ans;
}