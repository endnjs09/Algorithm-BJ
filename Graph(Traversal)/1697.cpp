#include <iostream>
#include <queue>
using namespace std;
#define SIZE 100000

bool visited[SIZE + 1];

struct Point {
    int x, cnt;
};

void bfs(int start, int end) {
    queue<Point> q;
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == end) {  // 위치에 도달
            cout << current.cnt;
            return;
        }

        int next[] = { current.x - 1, current.x + 1, 2 * current.x };

        for (int i = 0; i < 3; i++) {
            int nx = next[i];

            if (nx >= 0 && nx <= SIZE) {
                if (!visited[nx]) {
                    visited[nx] = true;
                    q.push({ nx, current.cnt + 1 });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    bfs(N, K);
}