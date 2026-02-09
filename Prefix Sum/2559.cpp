#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, res;
	cin >> n >> k;

	vector<int> v(n);
	vector<int> sum(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i - 1];
	}

	int max = -999;
	for (int i = k; i <= n; i++) {
		res = sum[i] - sum[i - k];
		if (res > max)
			max = res;
	}
	cout << max;
}
