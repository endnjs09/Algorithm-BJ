#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;	
	vector<int> v(n);
	vector<int> increase(n, 1);
	vector<int> decrease(n, 1);

	increase[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		for (int j = 0; j < i; j++) {
			if (v[j] < v[i])
				increase[i] = max(increase[i], increase[j] + 1);
		}
	}

	for (int i = n - 1; i >= 0; i--) {	
		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[i]) {
				decrease[i] = max(decrease[i], decrease[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ans = max(increase[i] + decrease[i] - 1, ans);
	}

	cout << ans;
}