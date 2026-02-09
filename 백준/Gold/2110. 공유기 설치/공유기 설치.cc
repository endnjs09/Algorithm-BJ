#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &arr, long long m, int C) {    
    // 집 좌표 배열, 공유기 사이의 거리, 공유기 개수
    int count = 1;
    int tmp = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] - tmp >= m) {
            count++;
            tmp = arr[i];
        }
    }

    if (count >= C) return true;    // 공유기 개수(3개) 보드 크면 true
    else return false;              // 작으면 false
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N, C;       // 집 개수, 공유기 개수
    cin >> N >> C;
    vector<int> v(N);

    for (int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long low = 1, high = v.back();   // 최소: 1, 최대: 802
    long long ans = 0;
    while(low <= high) {
        long long mid = (low + high) / 2;    // 시작 값: 중간값

        if (check(v, mid, C)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}