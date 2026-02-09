#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class p_queue {
    vector<int> v;
public:
    void push(int n) {
        v.push_back(n);
        int idx = v.size() - 1; // 방금 넣은 인덱스 

        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (v[idx] < v[parent]) { // 부모보다 더 크면
                swap(v[idx], v[parent]);
                idx = parent;
            }
            else break;
        }
    }

    int pop() {
        if (v.empty()) return -1;

        int root = v[0];    // root 값 
        v[0] = v.back();    // 맨 마지막 노드를 root로
        v.pop_back();       // 맨 마지막 노드 삭제

        int p = 0;
        while (p * 2 + 1 < v.size()) {  // 왼쪽에 자식이 있는지
            int L = p * 2 + 1;
            int R = p * 2 + 2;
            int child = L;

            if (R < v.size() && v[R] < v[L]) {  // 오른쪽 자식이 있고, 오른쪽 자식이 왼쪽보다 작으면
                child = R;
            }

            if (v[child] < v[p]) {      // 자식이 더 작으면
                swap(v[child], v[p]);   // 교체
                p = child;
            }
            else break;
        }
        return root;
    }

    bool empty() {
        if (v.empty()) return true;
        else return false;
    }

    int size() {
        return v.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    p_queue pq;

    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;

        pq.push(num);

        if (pq.size() > N) {
            pq.pop();
        }
    }

    cout << pq.pop();
}