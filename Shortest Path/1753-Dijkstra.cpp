#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int V, E, K;	// V: 정점, E: 간선, K: 시작점
int d[20002];	// 최단거리 배열
vector<pair<int, int>> adj[20002];	// <목적지, 가중치> 인접행렬

void dijkstra(int start) {	// 시작점 n

	for (int i = 0; i < 20002; i++) {	// 무한대로 초기화
		d[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// <가중치, 정점> 최소힙

	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dist = pq.top().first;		// 가중치 (0)
		int current = pq.top().second;	// 현재 정점 (1)
		pq.pop();

		if (d[current] < dist) {
			continue;
		}

		for (pair<int, int>& e : adj[current]) {	// e: adj[1] = { (2, 2), (3, 3) }
			int c = dist + e.second;				// (2, 2) 일 때 (1->2) c = 0 + 2 = 2 
			// (3, 3) 일 때 (1->3) c = 0 + 3 = 3

			if (c < d[e.first]) {	// 2 < d[2] 참
				d[e.first] = c;		// d[2] = 2로 갱신
				pq.push({ c, e.first });	// pq(2, 2) 삽입 >> pq = {(2,2), (3,3)} 
				// 왜냐 1에서 가장 가까운 점으로 가야하니까

				// d = {0, 2, 3, INF, INF}
				// 그 다음 current = 2, dist = 2가 되어서 이 기준으로 다시 
			}
		}
	}


	for (int i = 1; i <= V; i++) {

		if (d[i] == 1e9) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E >> K;

	for (int i = 1; i <= E; i++) {
		int u, v, w;			// u -> v 가중치 w
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
		// adj[1] = { (2, 2), (3, 3) }
		// adj[2] = { (3, 4), (4, 5) }
		// adj[3] = { (4, 6) }
		// adj[4] = {}
		// adj[5] = (1,1)
	}

	dijkstra(K);
}