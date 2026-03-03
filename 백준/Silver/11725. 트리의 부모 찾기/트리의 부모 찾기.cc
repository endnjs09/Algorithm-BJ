#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int SIZE = 100001;

vector<int> adj[SIZE];
int p[SIZE];    // 부모노드 저장

void tree(int node) {
    for (int next : adj[node]) {
        if (p[next] == 0) {
            p[next] = node;
            tree(next);
        }
    }
    // 부모로 복귀
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);    // u -> v
        adj[v].push_back(u);    // u -> v
    }

    memset(p, 0, sizeof(p));    p[1] = -1;
    tree(1);

    for (int i = 2; i <= N; i++) {
        cout << p[i] << '\n';
    }
}