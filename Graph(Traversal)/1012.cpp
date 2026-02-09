#include <iostream>
#include <queue>
using namespace std;

int M, N;
int adj[51][51];
bool visited[51][51];

struct Point {
    int x, y;
};

void bfs(int x, int y) {
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    queue<Point> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
                if (!visited[nx][ny] && adj[nx][ny] == 1) {     // 상하좌우 인접한 배추 방문 안했으면
                    visited[nx][ny] = true;     // 방문한 걸로 표시
                    q.push({ nx, ny });           // 다음 위치로
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int K, tCount = 0;
        cin >> M >> N >> K;

        for (int j = 0; j < N; j++) {       // 초기화
            for (int k = 0; k < M; k++) {
                adj[j][k] = 0;
                visited[j][k] = false;
            }
        }

        for (int j = 0; j < K; j++) {       // 배추 위치
            int x, y;
            cin >> x >> y;

            adj[y][x] = 1;
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (adj[j][k] == 1 && !visited[j][k]) {     // 배추가 있는데(1) 방문 안 한 경우
                    tCount++;                               // 지렁이 개수 증가 
                    bfs(j, k);      // 이 좌표를 넘김 (인접한 배추 모두 visited = true로 하기 위함)
                }
            }
        }

        cout << tCount << '\n';
    }
}

