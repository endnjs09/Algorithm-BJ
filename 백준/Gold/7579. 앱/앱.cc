#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<int> m(N);
    vector<int> c(N);

    int sum = 0;    // 전체 비용
    for (int i = 0; i < N; i++) {
        cin >> m[i];   // 메모리
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];   // 비용
        sum += c[i];
    }

    vector<int> dp(sum + 1, 0);

    for (int i = 0; i < N; i++) {
        int memory = m[i];
        int cost = c[i];

        for (int j = sum; j >= cost; j--) {
            dp[j] = max(dp[j], dp[j - cost] + memory);
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= M) {
            cout << i;
            break;
        }
    }
}