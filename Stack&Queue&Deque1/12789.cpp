#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n, next = 1;
	cin >> n;

	stack<int> tmp;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int k = 0;
	while (k < n) {
		if (v[k] == next) {	// next == 다음 학생 번호
			next++;
			k++;
		}
		else {
			tmp.push(v[k]);
			k++;
		}
		while (!tmp.empty() && tmp.top() == next) {
			next++;
			tmp.pop();
		}
	}

	if (next == n + 1)
		cout << "Nice";
	else cout << "Sad";
}
