#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> tmp;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int num : v) {

        if (tmp.empty() || num > tmp.back()) {  // 마지막 값보다 크면 넣음
            tmp.push_back(num);
        }
        else {  // 마지막 값 보다 작으면 들어갈 자리 찾음
            int t = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin(); // num 값보다 크거나 같은 위치
            tmp[t] = num;
        }
    }

    cout << tmp.size();
}