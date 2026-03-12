#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 4000001;
int N, M, K;
int parent[SIZE];
vector<int> v;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int rootX = find(x);    
    int rootY = find(y);
    // 루트 노드

    if (rootX == rootY) return;
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {   // 뽑은 카드
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());   // 이분탐색을 위한 정렬
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        
        int idx = upper_bound(v.begin(), v.end(), x) - v.begin();   // 이분탐색(x보다 큰값)
        int root = find(idx);
        cout << v[root] << '\n';
        unite(root + 1, root);
    }
} 