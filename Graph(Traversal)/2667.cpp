#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cnt = 0, N;
bool visited[26][26];

void dfs(vector<vector<int>>& v, int x, int y) {
    visited[x][y] = true;
    cnt++;

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };
    // x, y+1 // x, y-1 // x+1, y // x-1, y

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (v[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(v, nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N));
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            adj[i][j] = str[j] - '0'; // 문자를 숫자로 변환
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(adj, i, j);

                ans.push_back(cnt); // 나온 답을 저장
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}