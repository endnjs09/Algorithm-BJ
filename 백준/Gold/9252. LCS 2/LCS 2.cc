#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int A = a.size(), B = b.size();

    vector<vector<int>> dp(A + 1, vector<int>(B + 1, 0));
    for (int i = 0; i <= A; i++) dp[i][0] = 0;
    for (int j = 0; j <= B; j++) dp[0][j] = 0;

    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            if (a[i - 1] == b[j - 1]) { // 끝이 같을 경우
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // 끝이 다를 경우 (A에서 하나 뺀거랑 B에서 하나뺀거 비교)
        }
    }

    cout << dp[A][B] << '\n';

    vector<char> str;
    while (A != 0 && B != 0) {
        if (a[A - 1] == b[B - 1]) { // 문자가 같음 (좌상단에서 옴)
            str.push_back(a[A - 1]);
            A--;
            B--;
        }
        else {  // 문자가 다름
            if (dp[A][B] == dp[A][B - 1]) B--;  // dp 테이블에서 왼쪽 숫자와 같음
            else if (dp[A][B] == dp[A - 1][B]) A--; // dp 테이블에서 위쪽 숫자와 같음
        }
    }   // K > A > C > A 순으로 삽임

    for (int i = str.size() - 1; i >= 0; i--) {
        cout << str[i];
    }
}