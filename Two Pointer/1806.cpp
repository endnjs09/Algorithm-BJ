#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    int start = 0, end = 0, sum = 0, len = INF; // 임시 길이
    while (1) {
        if (sum >= S) { // 합이 S보다 크면
            len = min(len, end - start);    // 길이 갱신
            sum -= arr[start];  // 합에서 왼쪽 거 빼고 (그래도 크면 다시 뺌)
            start++;    // 한칸 이동
        }
        else if (end == arr.size()) break;
        else if (sum < S) { // 합이 S보다 작으면
            sum += arr[end];    // 합에서 오른쪽 거 더함
            end++;          // 한칸 이동
        }
    }

    int ans = len == INF ? 0 : len;
    cout << ans;
}