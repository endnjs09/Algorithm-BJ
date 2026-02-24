#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int a[31], dp[31][15001];   // 몇번째 추, 무게

void f(int n, int w) {   // 몇번째 추, 무게 차이 (0부터 시작)

    if (dp[n][w] != -1) return;

    dp[n][w] = 1;

    if (n == N) return;   // 추를 다 쓴 경우

    if (w + a[n] <= 15000) f(n + 1, w + a[n]);      // 더하기
    f(n + 1, abs(w - a[n])); // 빼기
    f(n + 1, w);             // 무시
}


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    f(0, 0);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        if (x > 15000) cout << 'N' << " ";
        else if (dp[N][x] == 1) cout << 'Y' << " ";
        else cout << 'N' << " ";
    }

}