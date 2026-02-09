#include <iostream>
using namespace std;
constexpr auto SIZE = 1000000;
typedef int element;

element stack[SIZE];
int top = -1;

element isEmpty() {	// 4번
	if (top == -1) return 1;
	else return 0;
}

void push(element x) {		// 1번
	stack[++top] = x;		// 정수 넣고 top 한칸 위로
}

void pop() {		// 2번
	if (isEmpty()) cout << -1 << '\n';
	else {
		cout << stack[top--] << '\n';
	}
}

void stackCount() {		// 3번
	cout << top + 1 << '\n';
}

void printTop() {
	if (isEmpty()) cout << -1 << '\n';
	else {
		cout << stack[top] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 1) {
			cin >> num;
			push(num);
		}
		else if (k == 2)
			pop();
		else if (k == 3) {
			stackCount();
		}
		else if (k == 4) {
			if (isEmpty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (k == 5) {
			printTop();
		}
	}
}