#include <iostream>
#include <queue>
using namespace std;

int adj[101];
bool visited[101];

struct Dice {
    int x, cnt;
};

void bfs(int start) { 
    int dice[] = {1, 2, 3, 4, 5, 6};
    queue<Dice> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        Dice current = q.front();
        q.pop();
        
        if (current.x == 100) {
            cout << current.cnt;
            return;
        }

        for (int i = 0; i < 6; i++) {
            int n = current.x + dice[i];

            if (n < 101) {
                if (adj[n] != 0) {  // 사다리, 뱀 있는 경우 
                    n = adj[n];
                }
                
                if (!visited[n])  { // 사다리 뱀 없음 (일반 칸인데 방문 x)
                    visited[n] = true;
                    q.push({n, current.cnt + 1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 0; i < 101; i++) adj[i] = 0;   // 초기화

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        adj[x] = y;
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u] = v;
    }

    bfs(1);
}

