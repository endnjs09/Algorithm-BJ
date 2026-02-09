#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, mod = 0;
	long long res = 0;
	cin >> n >> m;
	vector<long long> sum(n + 1, 0);
	vector<int> v(n);
	vector<long long> count(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum[i + 1] = sum[i] + v[i];
	}

	for (int i = 0; i <= n; i++) {
		mod = ((sum[i] % m) + m) % m;
		count[mod]++;
	}

	for (int i = 0; i < m; i++) {
		res += count[i] * (count[i] - 1) / 2;
	}
	cout << res;
}

