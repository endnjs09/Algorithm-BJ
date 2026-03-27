#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define SIZE 401

// capacity, flow
int cp[SIZE][SIZE], fw[SIZE][SIZE];
int parent[SIZE];   
vector<int> adj[SIZE];

int flow(int start, int end) {
    int total = 0;

    while (1) {
        fill(parent, parent + SIZE, -1);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int next : adj[current]) {
                // 잔여 용량 남았고 방문 안했으면
                if (cp[current][next] > fw[current][next] && parent[next] == -1) {
                    q.push(next);
                    parent[next] = current;
                    if (next == end) break;
                }
            }
        }
        // 더이상 경로가 없으면
        if (parent[end] == -1) break;

        int i = end;    // 도착지(2)에서 출발
        while (i != start) {    // 출발지에 도착할 때까지 역이동
            int p = parent[i];
            fw[p][i] += 1;  // 이동한 길
            fw[i][p] -= 1;  // 반대

            i = p;  
        }
        total++;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    cin >> N >> P;
    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cp[u][v] = 1;
    }

    cout << flow(1, 2);
}