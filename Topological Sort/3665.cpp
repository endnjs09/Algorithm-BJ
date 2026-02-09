#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int cnt[501];	// 진입 차수
int adj[501][501]; // 인접행렬

void fuck(int N) {
	vector<int> ans;
	queue<int>q;

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0)	// 진입 차수가 0이면 큐에 삽입
			q.push(i);
	}

	while (!q.empty()) {
		int current = q.front();	// current = 5
		q.pop();					// 5 제거
		ans.push_back(current);		// ans에 5 추가

		for (int i = 1; i <= N; i++) {
			if (adj[current][i] == 1) {			// adj[5][4, 3, 2, 1] == 1 
				cnt[i]--;						// cnt[5, 4, 3, 2, 1]--

				if (cnt[i] == 0) q.push(i);
			}
		}
	}

	if (ans.size() < N) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else if (q.size() > 1) {
		cout << '?' << '\n';
	}
	else {
		for (int k : ans) {
			cout << k << " ";
		}
		cout << '\n';
	}
}

int main() {
	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		memset(adj, 0, sizeof(adj));
		memset(cnt, 0, sizeof(cnt));

		int n;		// 팀의 수
		cin >> n;

		int rank[501];		// 작년 순위
		for (int j = 1; j <= n; j++) {
			cin >> rank[j];	// 5 4 3 2 1
		}

		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				adj[rank[j]][rank[k]] = 1;		// adj[5][4] = 1, adj[5][3] = 1 ...
				cnt[rank[k]]++;					// adj[4]++. adj[3]++...
			}
		}
		// 5 = {4, 3, 2, 1} = 1
		// 4 = {3, 2, 1} = 1
		// 3 = {2, 1} = 1
		// 2 = {1} = 1

		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;			// 2 4

			if (adj[b][a] == 1) {	// adj[4][2] == 1
				adj[b][a] = 0;		// adj[4][2] = 0
				adj[a][b] = 1;		// adj[2][4] = 1
				cnt[a]--;			// cnt[2]--
				cnt[b]++;			// cnt[4]++
			}
			else {					// adj[4][2] == 0
				adj[b][a] = 1;		// adj[4][2] = 1
				adj[a][b] = 0;		// adj[2][4] = 0
				cnt[b]--;			// cnt[4]--;
				cnt[a]++;			// cnt[2]++;
			}
		}

		fuck(n);
	}
}