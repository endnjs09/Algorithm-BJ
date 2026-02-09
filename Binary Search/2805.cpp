#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& arr, long long t, int M) {
    // 집 좌표 배열, 공유기 사이의 거리, 공유기 개수
    long long count = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] - t > 0) {
            count += arr[i] - t;
        }
    }

    if (count >= M) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;       // 나무의 수, 집으로 가져가려고 하는 나무의 길이 
    cin >> N >> M;
    vector<int> v(N);

    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];

        if (v[i] > max) max = v[i];
    }

    long long low = 1, high = max;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;

        if (check(v, mid, M)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}