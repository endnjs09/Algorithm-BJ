#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<int> arr;    // 입력용
    vector<int> r;
    vector<int> idx;  // 인덱스 저장용

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);

        if (r.empty() || num > r.back()) {  // 맨 끝 숫자와 비교
            r.push_back(num);
            idx.push_back(r.size() - 1);
        }
        else {
            int index = lower_bound(r.begin(), r.end(), num) - r.begin();     // 이분탐색 (num보다 크거나 같은 첫번 째 수)
            r[index] = num;         // 교체 (덮어씀)
            idx.push_back(index);   // 교체된 위치를 새로 추가 idx = { 0, 1, 0 }
        }
    }

    cout << r.size() << "\n";

    // arr = { 10 20 15 18 }
    // r = { 10 15 18 }
    // idx = { 0 1 1 2 }
    stack<int> a;   // 정답 출력용 스택
    int x = r.size() - 1;   // 끝지점 위치
    for (int i = idx.size() - 1; i >= 0; i--) {
        if (x == idx[i]) {
            if (x == -1) break;
            a.push(arr[i]);
            x--;
        }
    }

    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }

}