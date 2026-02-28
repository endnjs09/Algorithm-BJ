#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SIZE = 100000;

bool visited[SIZE + 1];
int r[SIZE + 1];

struct Point {
    int x, cnt;
};

void bfs(int start, int end) {
    queue<Point> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == end) {
            cout << current.cnt << '\n';
            break;
        }

        int next[] = { current.x - 1, current.x + 1, current.x * 2 };
        for (int i = 0; i < 3; i++) {
            int nx = next[i];

            if (nx >= 0 && nx <= SIZE) {
                if (!visited[nx]) {     // 방문 안했으면
                    visited[nx] = true;
                    r[nx] = current.x;  // 기록용
                    q.push({ nx, current.cnt + 1 });
                }
            }
        }
    }

    int x = end;
    vector<int> result;
    while (1) {
        result.push_back(x);
        if (x == start) break;
        x = r[x];
    }

    reverse(result.begin(), result.end());
    for (int i : result) cout << i << " ";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    bfs(n, k);
}