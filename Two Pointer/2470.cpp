#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9 + 1
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;      // 용액의 수
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    // -99, -2, -1, 4, 98

    int start = 0, end = arr.size() - 1, tmp = INF;
    int L, R;
    while (start < end) {
        long long sum = (long long)arr[start] + arr[end];

        if (abs(sum) < tmp) {
            tmp = abs(sum);      // 갱신용
            L = start;
            R = end;
        }

        if (sum < 0) start++;
        else if (sum > 0) end--;
        else break;
    }

    cout << arr[L] << " " << arr[R];
}