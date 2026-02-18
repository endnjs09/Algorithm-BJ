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

	dp[0] = v[0];	// 첫번째 계단
	dp[1] = max(dp[0] + v[1], v[1]);		// 두번째 계단 1->2 vs 2
	dp[2] = max(dp[0] + v[2], v[1] + v[2]); // 세번째 1->3 vs 2->3

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
	}
	
	// 4번째(dp[3]) 1->3->4 vs 2->4(1->2->4) >> 2까지 가는 건 알아서

	cout << dp[n - 1];
}