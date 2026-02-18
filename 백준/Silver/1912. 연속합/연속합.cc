#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n), dp(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = v[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(v[i], dp[i - 1] + v[i]);
	}

	// 1) 10
	// 2) -4 vs 10 + -4 >> 6 
	// 3) 3 vs 10 + ... + 3 >> 9
	// 4) 1 vs 10 + ... + 1 >> 10
	// 5) 5 vs 10 + ... + 5 >> 15
	// 6) 6 vs 10 + ... + 6 >> 21
	// 7) -35 vs 10 + ... + -35 >> -14
	// 8) 12 vs 10 + ... + 12 >> 12 (갱신됨)
	// 9) 21 vs 12 + 21 >> 33 (답)
	// 10) -1 vs 12 + 21 + -1 >> 32
	
	int ans = -1e9;
	for (int i = 0; i < n; i++) {
		ans = max(dp[i], ans);
	}

	cout << ans;
}