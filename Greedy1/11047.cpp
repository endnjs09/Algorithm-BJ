#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int money;
		cin >> money;
		v.push_back(money);
	}

	sort(v.rbegin(), v.rend());

	int i = 0, a, c = 0;
	while (k != 0) {
		if (k >= v[i]) {
			a = k / v[i];
			c += a;
			k %= v[i];

			i++;
		}
		else i++;
	}
	cout << c;
}