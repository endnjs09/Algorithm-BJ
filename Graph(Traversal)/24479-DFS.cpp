#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[100001], c = 0;
bool visited[100001];

void dfs(vector<vector<int>>& v, int start) {
    visited[start] = true;
    ans[start] = ++c;       // 방문 순서 카운트

    for (int next : v[start]) {    // 연결된 노드들 확인
        if (!visited[next]) {      // 방문하지 않았다면
            dfs(v, next);             // 더 깊이 들어감
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(adj, R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}
