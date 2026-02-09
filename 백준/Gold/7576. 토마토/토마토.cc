#include <iostream>
#include <queue>
using namespace std;

int M, N;
int adj[1001][1001];
bool visited[1001][1001];

struct Point {
    int x, y, cnt;
};

queue<Point> q;

void bfs(int &n) { 
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int ans = 0;

    while(!q.empty()) {
        Point current = q.front();
        q.pop();
        ans = current.cnt;

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
                if (!visited[nx][ny] && adj[nx][ny] == 0) {   // 인접한 토마토에 방문 x, 안 익음(0) 상태라면
                    visited[nx][ny] = true;
                    adj[nx][ny] = 1;
                    n--;    // 안 익은 토마토 개수 감소
                    q.push({nx, ny, current.cnt + 1});      // 다음 토마토로
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
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];

            if (adj[i][j] == 1) {       // 익은 토마토 
                q.push({i, j, 0});      // q에 넣기
                visited[i][j] = true;
            }
            else if (adj[i][j] == 0) {  // 안 익은 토마토
                tCount++;               // 카운트 증가 (이게 0이 되면 답)
            }
        }
    }
    
    if (tCount == 0) cout << 0;
    else bfs(tCount);
}
