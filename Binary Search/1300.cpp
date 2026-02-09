#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    long long low = 1, high = K, ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;     // 7번째 숫자를 중간값 5로 찍음
        long long count = 0;

        for (int i = 1; i <= N; i++) {
            count += min(mid / i, (long long)N);   // 5보다 작거나 같은수 6개. 7개가 안됨
        }

        if (count >= K) {   // 작거나 같은 수가 7개 이상이면      
            ans = mid;
            high = mid - 1; // 현재 mid 값보다 조건을 만족하는 더 작은 수가 있는지   
        }
        else {  // 5보다 더 큰 숫자로 해야함
            low = mid + 1;      // 범위가 6 ~ 16으로 갱신되고 mid = (6 + 16) / 2 = 11
        }
    }

    cout << ans;
}