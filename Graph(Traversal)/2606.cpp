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
    c++;

    while (!q.empty()) {
        int current = q.front();    // current = 1
        q.pop();                    // 제일 앞 1 삭제

        for (int next : v[current]) {   // int next = v[1] = { 2, 5 } 
            if (!visited[next]) {        // visited[2] = false 라면
                visited[next] = true;   // true로 바꾸고
                c++;
                q.push(next);           // 큐에 2 push
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //   1 2 3 4 5 6 7
    // 1 - o - - o - -      adj[1] = { 2, 5 } 
    // 2 o - o - o - -      adj[2] = { 1, 3, 5 }
    // 3 - o - - - - -      adj[3] = { 2 }
    // 4 - - - - - - o      adj[4] = { 7 }
    // 5 o o - - - o -      adj[5] = { 1 2 6 }
    // 6 - - - - o - -      adj[6] = { 5 }
    // 7 - - - o - - -      adj[7] = { 4 }

    bfs(adj, 1);

    cout << c - 1;
}