#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N, H;
int adj[101][101][101];
bool visited[101][101][101];

struct Point {
    int z, x, y, cnt;
};

queue<Point> q;

void bfs(int& n) {
    int dz[] = { 0, 0, 0, 0, 1, -1 };
    int dx[] = { 0, 0, 1, -1, 0, 0 };
    int dy[] = { 1, -1, 0, 0, 0, 0 };
    // (0, 0, 1) 오른쪽, (0, 0, -1) 왼쪽, (0, 1, 0) 위쪽, (0, -1, 0) 아래쪽
    // (1, 0, 0) 위층, (-1, 0, 0) 아래층

    int ans = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        ans = current.cnt;

        for (int i = 0; i < 6; i++) {       // 인접한 토마토 
            int nz = current.z + dz[i];
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if ((nz >= 0 && nz < H) && (nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
                if (!visited[nz][nx][ny] && adj[nz][nx][ny] == 0) {                             // 인접한 토마토에 방문 안했고 안 익음(0) 상태라면
                    adj[nz][nx][ny] = 1;                               // 익음 상태로 변경
                    n--;                                                // 안 익음 토마토 카운트 1 감소
                    q.push({ nz, nx, ny, current.cnt + 1 });              // 다음 토마토로 넘어감
                }
            }
        }
    }

    if (n == 0) cout << ans;
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int tCount = 0;
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> adj[i][j][k];
                if (adj[i][j][k] == 1) {
                    q.push({ i, j, k, 0 });
                    visited[i][j][k] = true;
                }
                else if (adj[i][j][k] == 0) {
                    tCount++;
                }
            }
        }
    }

    if (tCount == 0) cout << 0;
    else bfs(tCount);
}