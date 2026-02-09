#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> sum(n + 1, 0);
	vector<int> v(n);
	vector<int> ans(m);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum[i + 1] = sum[i] + v[i];
	}

	// sum[1] = sum[0](v[0]) + v[1]
	// sum[2] = sum[1] + v[2] = v[0] + v[1] + v[2]
	// sum[3] = sum[2] + v[3] = v[0] + v[1] + v[2] + v[3]

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ans[i] = sum[b] - sum[a - 1];
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}

}
