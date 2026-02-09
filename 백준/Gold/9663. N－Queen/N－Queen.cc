#include <iostream>
using namespace std;

int c = 0;	// 답
int n;	// 크기
bool colUsed[15], d[30], dd[30];	// 열, 대각선1, 대각선2

void queen(int row) {
	if (row == n) {
		c++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (!colUsed[col] && !d[row+col] && !dd[row - col + (n - 1)]) {
			colUsed[col] = true;
			d[row + col] = true;
			dd[row - col + (n - 1)] = true;
			queen(row + 1); // 행 + 1
			colUsed[col] = false;
			d[row + col] = false;
			dd[row - col + (n - 1)] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	queen(0);
	cout << c;
}