#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, k;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			pq.push(a);
		}

		long long sum = 0, total = 0;
		while (pq.size() >= 2) {
			long long x = pq.top();
			pq.pop();
			long long y = pq.top();
			pq.pop();

			sum = x + y;
			total += sum;
			pq.push(sum);
		}
		cout << total << '\n';
	}

}

