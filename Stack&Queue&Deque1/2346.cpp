#include <iostream>
#include <deque>
using namespace std;

void balloon(deque<pair<int, int>>& dq, int index) {

	int m = dq[index].second;
	cout << dq[index].first << " ";
	dq.erase(dq.begin() + index);

	if (dq.empty()) return;

	int size = dq.size();
	if (m > 0)
		index = (index + (m - 1)) % size;
	else
		index = (index + m) % size;
	if (index < 0) index += size;

	balloon(dq, index);
}

int main() {
	deque<pair<int, int>> dq;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		dq.push_back({ i, num });
	}

	balloon(dq, 0);
}