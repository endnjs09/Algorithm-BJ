#include <iostream>
using namespace std;

int M, N;
int arr[501][501], dp[501][501];

int f(int x, int y) {

    if (x == M - 1 && y == N - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;   // 방문 체크

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {  
            if (arr[x][y] > arr[nx][ny]) {  
                dp[x][y] += f(nx, ny);     
            }
        }
    }
    return dp[x][y];
}


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + (501 * 501), -1);
    cout << f(0, 0);
    
}