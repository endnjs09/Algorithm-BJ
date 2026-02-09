#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<vector<int>> t(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> t[i][j];
			v[i][j] = t[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		v[i][0] = v[i - 1][0] + t[i][0];

		for (int j = 1; j <= i; j++) {
			v[i][j] = max(v[i - 1][j - 1], v[i - 1][j]) + t[i][j];
		}

		v[i][i] = v[i - 1][i - 1] + t[i][i];
	}

	int ans = 0;
	for (int j = 0; j < n; j++)
		ans = max(ans, v[n - 1][j]);

	cout << ans;
}

