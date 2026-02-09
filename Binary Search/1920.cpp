#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) return 1;   // 찾음
        else if (arr[mid] > target) end = mid - 1;  // 중간값이 더 큼
        else start = mid + 1;    // 중간값이 더 작음
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        if (binarySearch(v, num)) {
            cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }
}