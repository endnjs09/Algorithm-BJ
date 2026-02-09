#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	int sum = 0, p = 0;
	for (int i = 0; i < n; i++) {    // SJF
		p += v[i];
		sum += p;
	}
	cout << sum;

}