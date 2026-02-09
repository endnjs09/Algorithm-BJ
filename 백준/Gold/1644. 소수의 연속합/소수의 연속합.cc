#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

void f(int n) {
    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (arr[i]) {   // 소수

            for (int j = i * i; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (arr[i]) {
            v.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    f(N);
    // v = { 2, 3, 5, 7, 11, 13, 17, 19 }

    int start = 0, end = 0, sum = 0, count = 0;
    while (1) {
        if (sum >= N) {
            if (sum == N) count++;
            sum -= v[start];
            start++;
        }
        else if (end == v.size()) {
            break;
        }
        else if (sum < N) {
            sum += v[end];
            end++;
        }
    }

    int ans = count == 0 ? 0 : count;
    cout << ans;
}