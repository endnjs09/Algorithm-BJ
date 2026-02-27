#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[1001]; // <목적지, 가중치>
vector<int> tmp(1001);  // 임시 저장용
int d[1001];    // 최소 비용

const int INF = 1e9;

void dj(int start, int end) {

    for (int i = 0; i < 1001; i++) d[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    d[start] = 0;
    pq.push({ 0, start });  
    
    while (!pq.empty()) {
        int w = pq.top().first;  // 가중치
        int current = pq.top().second;  // 현재 도시
        pq.pop();

        if (current == end) break;  // 목적지에 도착했으면 종료
        if (d[current] < w) continue;    

        for (pair<int, int>& e : adj[current]) {    // 현재 정점에서 다음 도시를 순차적으로 확인 (e는 다음 정점)
            int cost = w + e.second;    // 현재 가중치에 다음 도시로 가는 가중치를 더한 값

            if (cost < d[e.first]) {    
                tmp[e.first] = current; // 방문 도시 기록
                d[e.first] = cost;
                pq.push({ cost, e.first });
            }
        }
    }

    cout << d[end] << '\n'; // end까지의 최소 비용

    int x = end;
    vector<int> result;
    while (1) {
        result.push_back(x);
        if (x == start) break;
        x = tmp[x];
    }

    cout << result.size() << '\n';

    reverse(result.begin(), result.end());
    for (int i : result) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;       
        cin >> u >> v >> w;
        
        adj[u].push_back({ v, w }); // u -> v 가중치 w
    }

    int start, end;
    cin >> start >> end;
    dj(start, end);
}