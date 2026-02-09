#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f(int i, long long sum, vector<int>& w, vector<long long>& a) {
    if (i == w.size()) {
        a.push_back(sum);
        return;
    }

    f(i + 1, sum, w, a);    // 물건 안 넣음
    f(i + 1, sum + w[i], w, a);     // 물건 넣음
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, C;   // 물건 개수, 가방 무게
    cin >> N >> C;

    vector<int> leftW, rightW;   // 왼쪽 무게, 오른쪽 무게
    for (int i = 0; i < N; i++) { 
        int w;
        cin >> w;

        if (i < N / 2) leftW.push_back(w);  // 0~14 왼쪽
        else rightW.push_back(w);           // 15~29 오른쪽
    }
    

    vector<long long> L, R;   // 누적합 결과 
    f(0, 0, leftW, L); f(0, 0, rightW, R);

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    long long left = 0, right = R.size() - 1;
    long long count = 0;
    while (left < L.size() && right >= 0) {
        if (L[left] + R[right] <= (long long)C) {  // 왼쪽의 합 + 오른쪽의 합(끝) 더해도 무게 충분
            count += (long long)right + 1;
            left++;
        }
        else right--;
    }

    cout << count;
}