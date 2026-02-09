#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int x;
    cin >> x;

    int start = 0, end = arr.size() - 1, count = 0;
    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum == x) {
            count++;
            start++;
            end--;
        }
        else if (sum < x) { // 합이 x보다 작음
            start++;
        }
        else {  // 합이 x보다 큼
            end--;
        }
    }

    cout << count;
}