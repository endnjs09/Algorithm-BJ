#include <iostream>
#define INF 1e9
using namespace std;

int d[401][401];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {              // 거쳐가는 도시
        for (int i = 1; i <= n; i++) {          // 출발
            for (int j = 1; j <= n; j++) {      // 도착
                if (d[i][k] + d[k][j] < d[i][j]) {  // k를 거쳐갔을 때 더 빠르면
                    d[i][j] = d[i][k] + d[k][j];    // 갱신
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;            // 시작, 도착, 거리
        cin >> a >> b >> c;

        d[a][b] = min(d[a][b], c);

        //   1 2 3
        // 1 - 1 5
        // 2 - - 2
        // 3 - 1 - 
        // (1,1) (2,2) (3,3)이 각각 자기 자신으로 돌아오는 값
    }

    floyd(V);

    int ans = d[1][1];
    for (int i = 1; i <= V; i++) {
        ans = min(d[i][i], ans);
    }

    if (ans >= INF) cout << -1;
    else cout << ans;

}