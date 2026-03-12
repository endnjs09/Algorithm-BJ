#include <iostream>
using namespace std;

const int SIZE = 100001;
int parent[SIZE];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int rootX = find(x);    
    int rootY = find(y);
    // 루트 노드

    if (rootX == rootY) return;
    parent[rootY] = rootX;
}

bool isUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    // 루트 노드

    if (rootX == rootY) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int G, P, cnt = 0;
    cin >> G >> P;
    for (int i = 0; i <= G; i++) parent[i] = i;

    for (int i = 0; i < P; i++) {
        int n;
        cin >> n;

        int root = find(n);
        if (root == 0) break;
        else {
            cnt++;
            unite(root - 1, root);
        }
    }
    cout << cnt;
} 