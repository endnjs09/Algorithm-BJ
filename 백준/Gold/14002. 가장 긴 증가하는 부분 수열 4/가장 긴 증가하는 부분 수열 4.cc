#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> dp(N, 1);
    vector<int> r(N, -1);   // 기록용

    for (int i = 0; i < N; i++) cin >> v[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    r[i] = j;   // 갱신될 때 그전의 인덱스
                }
            }
                
        }
    }

    int max = 0, index = 0;  // 가장 긴 길이
    for (int i = 0; i < N; i++) {
        if (dp[i] > max) {
            max = dp[i];
            index = i;  // 위치
        }
    }
    cout << max << '\n';
    
    vector<int> tmp;
    while (1) {
        tmp.push_back(v[index]);
        if (r[index] == -1) break;
        index = r[index];
    }

    for (int i = tmp.size() - 1; i >= 0; i--) {
        cout << tmp[i] << " ";
    }
    

}