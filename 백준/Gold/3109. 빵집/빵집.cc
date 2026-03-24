#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
char adj[10001][501];
bool visited[10001][501];

// 오른쪽, 오른쪽, 오른쪽 아래
int dr[] = { -1, 0, 1 };

bool dfs(int r, int c) {
    visited[r][c] = true;

    if (c == C - 1) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + 1;

        // 범위 체크 + 건물 아님 + 방문 안 함
        if (nr >= 0 && nr < R && nc < C) {
            if (adj[nr][nc] == '.' && !visited[nr][nc]) {

                // 이 길로 쭉 갔을 때 끝까지 도달한다면
                if (dfs(nr, nc)) {
                    return true; // 바로 true 반환 종료
                }
            }
        }
    }

    // 세 방향 다 가봤는데 안 되면 실패
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C)) return 0;

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            adj[i][j] = row[j];
        }
    }

    int cnt = 0;
    // 모든 행에서 출발
    for (int i = 0; i < R; i++) {
        if (dfs(i, 0)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}