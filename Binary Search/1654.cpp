#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool lans(vector<int>& arr, long long length, int K) {
    // 랜선 길이 배열, 자를 랜선 길이(구하고자 하는 거), 필요한 랜선 개수(11)
    int count = 0;

    for (int i : arr) {
        count += i / length;
    }

    if (count >= K) return true;    // 필요한 랜선 개수(11) 보다 크면 true
    else return false;              // 필요한 랜선 개수보다 작으면 false
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    long long low = 1, high = *max_element(v.begin(), v.end());   // 최소: 1, 최대: 802
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;     // 중앙값으로 시작

        if (lans(v, mid, K)) {   // K개를 만들 수 있음
            ans = mid;
            low = mid + 1;
        }
        else {  // K개를 못 만듦 >> 랜선 길이(mid)가 너무 큼
            high = mid - 1;
        }
    }

    cout << ans;
}