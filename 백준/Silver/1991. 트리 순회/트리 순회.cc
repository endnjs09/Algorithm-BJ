#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adj[26][2]; // [][0]:왼쪽, [][1]:오른쪽

void preorder(int root) {   // 부왼오
    if (root != -1) {
        cout << (char)(root + 'A');
        preorder(adj[root][0]);
        preorder(adj[root][1]);
    }
}

void inorder(int root) {    // 왼부오
    if (root != -1) {
        inorder(adj[root][0]);
        cout << (char)(root + 'A');
        inorder(adj[root][1]);
    }
}

void postorder(int root) {  // 왼오부
    if (root != -1) {
        postorder(adj[root][0]);
        postorder(adj[root][1]);
        cout << (char)(root + 'A');
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char x, y, z;
        cin >> x >> y >> z;

        int a, b, c;
        a = x - 'A';   // A = 0
        b = (y == '.') ? -1 : y - 'A';  // B = 1
        c = (z == '.') ? -1 : z - 'A';  // C = 2

        adj[a][0] = b;  // 왼쪽
        adj[a][1] = c;  // 오른쪽
    }
    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0); cout << '\n';
}