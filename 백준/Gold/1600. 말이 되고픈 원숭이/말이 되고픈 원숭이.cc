#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int K, W, H;

struct Point {
    int x, y, cnt, jmp;
};

bool visited[201][201][31];

void bfs(vector<vector<int>>& v, int n, int x, int y) {

    queue<Point> q;
    q.push({ 0, 0, 0, n});
    visited[0][0][n] = true;    // n번의 점프 기회

    // 상하좌우
    int dx[] = { 0, 0, 1, -1 }; 
    int dy[] = { 1, -1, 0, 0 }; 

    // 말 점프
    int hdx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    int hdy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == x - 1 && current.y == y - 1) {       // 목적지에 도달
            cout << current.cnt;                // 답 출력
            return;
        }

        for (int i = 0; i < 4; i++) {   // 인접하게 가는 방식
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < x && ny >= 0 && ny < y) {

                if (v[nx][ny] == 0 && !visited[nx][ny][current.jmp]) {   // 방문하지 않았고 길(0)이라면
                    visited[nx][ny][current.jmp] = true;                 // 방문 체크
                    q.push({ nx, ny, current.cnt + 1, current.jmp });      // 큐에 push (다음 칸으로)
                }
            }
        }


        for (int i = 0; i < 8; i++) {
            int hnx = current.x + hdx[i];
            int hny = current.y + hdy[i];

            if (current.jmp > 0) {  // 점프 기회가 남아있음

                if (hnx >= 0 && hnx < x && hny >= 0 && hny < y) {   // 맵 범위

                    if (v[hnx][hny] == 0 && !visited[hnx][hny][current.jmp - 1]) {  // 점프 했을 때 위치가 길이고 방문하지 않음
                        visited[hnx][hny][current.jmp - 1] = true;
                        q.push({ hnx, hny, current.cnt + 1, current.jmp - 1 });
                    }
                }
            }
        }

    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> K >> W >> H;

    vector<vector<int>> adj(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> adj[i][j];
        }
    }

    bfs(adj, K, H, W);
}