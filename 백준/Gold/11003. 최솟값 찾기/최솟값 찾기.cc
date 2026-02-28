#include <iostream>
#include <vector>
#include <deque> 
#include <algorithm>
using namespace std;

const int SIZE = 5000001;
int arr[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;

    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {

        while (!dq.empty() && arr[i] <= dq.back().first) {  
            dq.pop_back();
        }
        dq.push_back({ arr[i], i });

        if (dq.front().second < i - L + 1) { // 첫번째 수의 인덱스가 범위를 벗어남
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }
}