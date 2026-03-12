#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SIZE = 1000001;
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

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 0) {
            unite(a, b);
        }
        else {
            if (isUnion(a, b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}