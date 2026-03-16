#include <iostream>
#include <queue>
#include <string>

using namespace std;

char adj[11][11];
bool visited[11][11][11][11];

struct Point {
    int rx, ry, bx, by, depth;
};

int move(int& x, int& y, int d) {
    // 0:아래, 1:위, 2:오른쪽, 3:왼쪽
    int dx[] = { 0, 0, 1, -1 }; 
    int dy[] = { 1, -1, 0, 0 };
    int dist = 0;

    while (adj[y + dy[d]][x + dx[d]] != '#') {
        x += dx[d];
        y += dy[d];
        dist++;

        if (adj[y][x] == 'O') return -1; // 구멍에 빠지면 -1
    }
    return dist;
}

int bfs(int rx, int ry, int bx, int by) {
    queue<Point> q;
    q.push({ rx, ry, bx, by, 0 });
    visited[ry][rx][by][bx] = true;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.depth >= 10) continue;

        for (int i = 0; i < 4; i++) {
            int nrx = current.rx, nry = current.ry;
            int nbx = current.bx, nby = current.by;

            int distR = move(nrx, nry, i);
            int distB = move(nbx, nby, i);

            if (distB == -1) continue;      // 파란색 빠지면 실패
            if (distR == -1) return current.depth + 1; // 빨간색만 빠지면 성공

            if (nrx == nbx && nry == nby) {
                if (distR > distB) { 
                    nrx -= dx[i]; 
                    nry -= dy[i]; 
                }
                else { 
                    nbx -= dx[i]; 
                    nby -= dy[i]; 
                }
            }

            if (!visited[nry][nrx][nby][nbx]) { // 방문 체크
                visited[nry][nrx][nby][nbx] = true;
                q.push({ nrx, nry, nbx, nby, current.depth + 1 });
            }
        }
    }
    return -1; // 10번 안에 못 찾으면 -1
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int rx, ry, bx, by;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            adj[i][j] = str[j];
            if (adj[i][j] == 'R') { 
                rx = j; 
                ry = i; 
                adj[i][j] = '.'; 
            }
            else if (adj[i][j] == 'B') { 
                bx = j; 
                by = i; 
                adj[i][j] = '.'; 
            }
        }
    }
    cout << bfs(rx, ry, bx, by);
}