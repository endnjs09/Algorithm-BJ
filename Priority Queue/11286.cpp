#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class p_queue {
    vector<int> v;
public:
    void push(int n) {
        v.push_back(n);
        int idx = v.size() - 1; // 방금 넣은 인덱스 

        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (abs(v[idx]) < abs(v[parent])) { // 추가한 노드가 부모보다 더 작으면
                swap(v[idx], v[parent]);
                idx = parent;
            }
            else if (abs(v[idx]) == abs(v[parent])) {
                if (v[idx] < v[parent]) {
                    swap(v[idx], v[parent]);
                    idx = parent;
                }
                else break;
            }
            else break;
        }
    }

    int pop() {
        if (v.empty()) return 0;

        int root = v[0];    // root 값 
        v[0] = v.back();    // 맨 마지막 노드를 root로
        v.pop_back();       // 맨 마지막 노드 삭제

        int current = 0;
        while (current * 2 + 1 < v.size()) {
            // 왼쪽에 자식이 있는지 (왼쪽에 자식이 없으면 오른쪽에도 없음) 자식이 없을 때까지 내려감

            int L = current * 2 + 1;
            int R = current * 2 + 2;
            int child = L;  // 왼쪽이 더 작다고 가정함

            if (R < v.size() && abs(v[R]) < abs(v[L])) {  // 오른쪽 자식이 있고, 오른쪽 자식이 왼쪽보다 작으면
                child = R;  // 오른쪽으로
            }
            else if (R < v.size() && abs(v[R]) == abs(v[L])) {
                if (v[R] < v[L]) {
                    child = R;
                }
            }

            if (abs(v[child]) < abs(v[current])) {       // 자식의 절대 값이 더 작으면
                swap(v[child], v[current]);              // 교체
                current = child;
            }
            else if (abs(v[child]) == abs(v[current])) {    // 절대값이 같으면
                if (v[child] < v[current]) {                // 원래 값이 더 작은 걸로
                    swap(v[child], v[current]);
                    current = child;
                }
                else break;
            }
            else break;
        }
        return root;
    }

    bool empty() {
        if (v.empty()) return true;
        else return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    p_queue pq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            cout << pq.pop() << '\n';
        }
        else pq.push(num);
    }
}