#include <iostream>
using namespace std;

const int SIZE = 10001;
int preorder[SIZE];

void f(int x, int y) {
    if (x > y) return;

    int p = preorder[x];
    int i = x + 1;
    while (i <= y) {    // 루트보다 큰 위치
        if (preorder[i] > preorder[x]) break;
        i++;
    }

    f(x + 1, i - 1);
    f(i, y);

    cout << p << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    while (1) {
        int n;
        cin >> n;

        if (cin.eof()) break;
        preorder[i] = n;
        i++;
    }

    f(0, i - 1);
}