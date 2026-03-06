#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int SIZE = 40001;
vector<pair<int, int>> adj[SIZE];
int dist[SIZE], depth[SIZE], p[SIZE][17];

void f(int start) {
    queue<pair<int,int>> q;
    q.push({ start, 0 });
    dist[start] = 0;
    depth[start] = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int w = q.front().second;
        q.pop();

        for (auto& n : adj[current]) {
            int next = n.first;
            int next_w = w + n.second;

            if (dist[next] == -1) {
                dist[next] = next_w;
                depth[next] = depth[current] + 1;   // 다음 층으로 이동
                p[next][0] = current;               // next의 1칸(2^0) 위 노드 = current
                q.push({ next, next_w });
            }
        }
    }
}

int g(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    int tmp = depth[y] - depth[x];

    for (int k = 0; k < 17; k++) {  // 비트연산
        if (tmp & (1 << k))
            y = p[y][k];
    }

    if (x == y) return x;   // LCA
    else {
        for (int k = 16; k >= 0; k--) {
            if (p[x][k] != p[y][k]) {
                x = p[x][k];
                y = p[y][k];
            }
        }
        return p[x][0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;   
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    memset(dist, -1, sizeof(dist));
    f(1);   // dist 채우기 (시작점: 1 고정) 

    for (int k = 1; k < 17; k++) {  // LCA
        for (int node = 1; node <= N; node++) {
            p[node][k] = p[p[node][k - 1]][k - 1];
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        int LCA = g(u, v);
        cout << dist[u] + dist[v] - 2 * dist[LCA] << '\n';
    }

}