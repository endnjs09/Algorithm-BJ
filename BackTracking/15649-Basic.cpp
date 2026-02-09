#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int>& v, vector<bool>& visited, vector<int>& result, int d, int n, int m) {
	if (d == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[d] = v[i];
			permutation(v, visited, result, d + 1, n, m);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> v;	// 1 ~ n
	vector<bool> visited(n);
	vector<int> result(n);

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	permutation(v, visited, result, 0, n, m);
}