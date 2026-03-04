#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int SIZE = 100001;
vector<pair<int, int>> adj[SIZE];
int d[SIZE];

void f(int start) {
    
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    d[start] = 0;

    while (!q.empty()) {
        int current = q.front().first;  
        int dist = q.front().second;
        q.pop();

        for (auto& n : adj[current]) {
            int next = n.first;
            int next_d = dist + n.second;

            if (d[next] == -1) {     // 방문 안했으면
                d[next] = next_d;
                q.push({ next, next_d });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;      // 정점 개수
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u;      // 시작점
        cin >> u;

        while (1) {
            int v, w;   // 도착점, 가중치
            cin >> v;

            if (v == -1) break;
            else cin >> w;
            
            adj[u].push_back({ v, w });
        }
    }

    memset(d, -1, sizeof(d));
    f(1);       // 끝지점의 인덱스 구하기 
    int index = 1;
    for (int i = 2; i <= N; i++) {
        if (d[index] < d[i]) {
            index = i;
        }
    }

    memset(d, -1, sizeof(d));
    f(index);   // 끝지점에서 각 점까지 가는 최대치
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(d[i], result);
    }

    cout << result;
}