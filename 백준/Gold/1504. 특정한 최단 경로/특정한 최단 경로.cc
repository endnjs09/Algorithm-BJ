#include <iostream>
#include <vector>
#include <queue>
#define INF 1e8
#define SIZE 200001
using namespace std;

int N, E;	// N: 정점의 개수(목적지), E: 간선의 개수
int d[SIZE];	// 최단거리 배열
vector<pair<int, int>> adj[801];	// <목적지, 가중치> 인접행렬

void dijkstra(int start) {

	for (int i = 0; i < SIZE; i++) {	// 무한대로 초기화
		d[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;	// <가중치, 정점> 최소힙

	d[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		int dist = pq.top().first;		// 가중치 
		int current = pq.top().second;	// 현재 정점 
		pq.pop();

		if (d[current] < dist) {	
			continue;	
		}

		for (pair<int, int>& e : adj[current]) {	
			int c = dist + e.second;				
											
			if (c < d[e.first]) {		// 거리비교
				d[e.first] = c;			// 갱신
				pq.push({c, e.first});	

			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> E;

	for (int i = 1; i <= E; i++) {
		int u, v, w;			// u -> v 가중치 w
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
		// adj[1] = {(2,3), (4,4), (3,5)}
		// adj[2] = {(1,3), (3,3), (4,5)}
		// adj[3] = {(1,5), (2,3), (4,1)}
		// adj[4] = {(1,4), (2,5), (3,1)}
	}

	int v1, v2;
	cin >> v1 >> v2;

	dijkstra(1); 
	int start_v1 = d[v1];	// 1에서 v1
	int start_v2 = d[v2];	// 1에서 v2

	dijkstra(v1);
	int v1_v2 = d[v2];	// v1에서 v2
	int v1_N = d[N];	// v1에서 N

	dijkstra(v2);
	int v2_N = d[N];	// v2에서 N

	long long res = min((long long)start_v1 + v1_v2 + v2_N, (long long)start_v2 + v1_v2 + v1_N);
	if (res >= INF) cout << -1;
	else cout << res;
}