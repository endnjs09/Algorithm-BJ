#include <iostream>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;

vector<pair<int, int>> adj[501];
long long d[501];
int N, M;

bool bf(int start) {
    d[start] = 0;
    for (int i = 1; i <= N; i++) {  // N번째에서 가중치가 줄어들면 음수 사이클
        for (int j = 1; j <= N; j++) { // 출발
            for (auto& e : adj[j]) {    
                int v = e.first;    // 도착(2)
                int w = e.second;   // 시간(4)

                if (d[j] != INF && d[v] > d[j] + w) {
                    d[v] = d[j] + w;

                    if (i == N) return true;   
                }
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) d[i] = INF;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });

        // adj[1] = {(2,4), (3,3)}
        // adj[2] = {(3,-1)}
        // adj[3] = {(1,-2)}
    }

    if (bf(1)) cout << -1 << '\n';
    else {
        for (int i = 2; i <= N; i++) {
            if (d[i] == INF) cout << -1 << '\n';
            else cout << d[i] << '\n';
        }
    }
}