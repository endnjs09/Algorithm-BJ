#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
#define SIZE 2001
using namespace std;

vector<pair<int, int>> adj[SIZE];

void ud(int start, int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (가중치, 정점)
    arr[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (arr[current] < dist) continue;

        for (pair<int, int>& e : adj[current]) {
            int c = dist + e.second;

            if (c < arr[e.first]) {
                arr[e.first] = c;
                pq.push({ c, e.first });
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        for (int i = 0; i < SIZE; i++) adj[i].clear();

        int n, m, t;        // 교차로(정점), 도로(간선), 목적지 후보 개수
        cin >> n >> m >> t;

        int s, g, h;        // 범인 출발지, 목격된 도로
        cin >> s >> g >> h;

        int a, b, d;        // a <-> b (시간 d)
        for (int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            adj[a].push_back({ b, d });
            adj[b].push_back({ a, d });
        }

        int ds[SIZE], dg[SIZE], dh[SIZE];
        ud(s, ds);  ud(g, dg);  ud(h, dh);
        vector<int> ans;

        for (int j = 0; j < t; j++) {
            int x; // 범인 도착 지점
            cin >> x;

            // s -> g -> h -> x, vs s -> h -> g -> x (g -> h랑 h->g는 같음)
            long long p = min((long long)ds[g] + dg[h] + dh[x], (long long)ds[h] + dh[g] + dg[x]);
            long long sx = ds[x];

            if (sx != INF && sx == p) {   // s->...->x 최단거리와 g->h 거쳐서 가는 거리가 같음
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());

        for (int o : ans) {
            cout << o << " ";
        }
        cout << '\n';
    }
}