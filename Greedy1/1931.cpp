#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorts(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int num, end = 0, count = 0;
	cin >> num;
	vector<pair<int, int>> v(num);
	for (int i = 0; i < num; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), sorts);

	for (int i = 0; i < num; i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			count++;
		}
	}

	cout << count;
}

