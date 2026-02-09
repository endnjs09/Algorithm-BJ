#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int x, y, cnt;
};

bool visited[101][101];

void bfs(vector<vector<int>>& v, int x, int y) {
    queue<Point> q;
    q.push({ 0, 0, 1 });
    visited[0][0] = true;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == x - 1 && current.y == y - 1) {       // 목적지에 도달
            cout << current.cnt;                // 답 출력
            return;
        }

        for (int i = 0; i < 4; i++) {   // 현재 위치에서 방향 벡터 더함
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
                if (!visited[nx][ny] && v[nx][ny] == 1) {   // 방문하지 않았고 길(1)이라면
                    visited[nx][ny] = true;                 // 방문했다고 체크
                    q.push({ nx, ny, current.cnt + 1 });      // 큐에 push (다음 칸으로)
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            adj[i][j] = str[j] - '0';
        }
    }

    bfs(adj, N, M);
}