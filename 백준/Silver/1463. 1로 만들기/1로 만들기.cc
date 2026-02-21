#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k;
	cin >> k;
	vector<int> dp(k + 1);
	
	dp[1] = 0;

	for (int n = 2; n <= k; n++) {

		if (n % 6 == 0) 
			dp[n] = min({ dp[n / 3], dp[n / 2], dp[n - 1] }) + 1;	// 6의 배수
		else if (n % 3 == 0) 
			dp[n] = min(dp[n / 3], dp[n - 1]) + 1;			// 3의 배수
		else if (n % 2 == 0) 
			dp[n] = min(dp[n / 2], dp[n - 1]) + 1;			// 2의 배수
		else 
			dp[n] = dp[n - 1] + 1;			// 그외

	}

	cout << dp[k];
	
}