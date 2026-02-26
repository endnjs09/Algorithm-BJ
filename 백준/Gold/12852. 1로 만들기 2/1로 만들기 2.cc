#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);   
    vector<int> a(N + 1, 0);    // 기록용

    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        
        if (i % 6 == 0) {
            int tmp = min({ dp[i / 3], dp[i / 2],dp[i - 1] });
            dp[i] = tmp + 1;

            if (tmp == dp[i / 3]) a[i] = i / 3;
            else if (tmp == dp[i / 2]) a[i] = i / 2;
            else a[i] = i - 1;
        }
        else if (i % 3 == 0) {
            int tmp = min({ dp[i / 3], dp[i - 1] });
            dp[i] = tmp + 1;

            if (tmp == dp[i / 3]) a[i] = i / 3;
            else a[i] = i - 1;
        }
        else if (i % 2 == 0) {
            int tmp = min({ dp[i / 2], dp[i - 1] });
            dp[i] = tmp + 1;

            if (tmp == dp[i / 2]) a[i] = i / 2; 
            else a[i] = i - 1;
        }
        else {
            dp[i] = dp[i - 1] + 1; 
            a[i] = i - 1;
        }

    }

    cout << dp[N] << '\n';
    int c = N;
    while (1) {
        cout << c << " ";
        if (c == 1) break;
        c = a[c];   // 다음으로 이동
    }

}