#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[301][301];

struct Point {
    int x, y, cnt;
};

void bfs(int x1, int y1, int x2, int y2, int size) {
    if (x1 == x2 && y1 == y2) {    // 출발과 도착이 같음
        cout << 0 << '\n';
        return;
    }

    queue<Point> q;
    q.push({ x1, y1, 0 });
    visited[x1][y1] = true;

    while (!q.empty()) {
        int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };   // 이동 x
        int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };   // 이동 y

        Point current = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];     // 이동 후 x좌표
            int ny = current.y + dy[i];     // 이동 후 y좌표

            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;

                    if (nx == x2 && ny == y2) {             // 도착점과 같음 (답)
                        cout << current.cnt + 1 << "\n";
                        return;
                    }
                    else q.push({ nx, ny, current.cnt + 1 });
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
        int L;
        cin >> L;

        for (int r = 0; r < L; r++) {
            for (int c = 0; c < L; c++) {
                visited[r][c] = false;
            }
        }

        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        bfs(x1, y1, x2, y2, L);
    }
}