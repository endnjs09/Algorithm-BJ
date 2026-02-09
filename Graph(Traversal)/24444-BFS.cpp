#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ans[100001], c = 0;
bool visited[100001];

void bfs(vector<vector<int>>& v, int start) {
    queue<int> q;
    q.push(start);          // 큐에 1 push
    visited[start] = true;
    ans[start] = ++c;       // 방문 순서 카운트, ans[1] = 1

    while (!q.empty()) {
        int current = q.front();    // current = 1
        q.pop();                    // 제일 앞 1 삭제

        for (int next : v[current]) {   // int next = v[1] = { 2, 4 } 
            if (!visited[next]) {        // visited[2] = false 라면
                visited[next] = true;   // true로 바꾸고
                ans[next] = ++c;        // 방문 순서 카운트, ans[2] = 2
                q.push(next);           // 큐에 2 push
            }
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

    //   1 2 3 4 5
    // 1 - o - o -      adj[1] = { 2, 4 } 
    // 2 o - o o -      adj[2] = { 1, 3, 4 }
    // 3 - o - o -      adj[3] = { 2 , 4 }
    // 4 o o o - -      adj[4] = [ 1, 2, 3 ]
    // 5 - - - - -      adj[5] = { }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(adj, R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}
