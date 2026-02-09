#include <iostream>
#include <vector>
#include <algorithm>
#define COLOR 3
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> d(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < COLOR; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		d[i][0] += min(d[i - 1][1], d[i - 1][2]);	// 1번집이 빨강색인 경우 (0번집은 파랑 or 초록) 
		d[i][1] += min(d[i - 1][0], d[i - 1][2]);	// 1번집이 초록색인 경우 (0번집은 빨강 or 파랑) 
		d[i][2] += min(d[i - 1][0], d[i - 1][1]);	// 1번집이 파랑색인 경우 (0번집은 빨강 or 초록) 
	}

	int res = min({ d[n - 1][0], d[n - 1][1], d[n - 1][2] });

	cout << res;
}