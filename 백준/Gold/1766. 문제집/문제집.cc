#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;	// 문제 수, 정보
int cnt[32001];	// 진입 차수
vector<int> adj[32001];

void fuck() {
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> q;	// 순서가 있으니까 우선순위큐로 해야됨 (최소 힙)

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {	// 진입 차수가 0이면
			q.push(i);		// 큐에 삽입 (3이 들어감)
		}
	}

	while (!q.empty()) {
		int current = q.top();	// current = 3
		q.pop();					// 3 제거
		ans.push_back(current);		// ans에 3 추가

		for (int n : adj[current]) { // n : adj[3] = {1}
			cnt[n]--;				 // cnt[1]--

			if (cnt[n] == 0) {		// cnt[1] == 0 이니까 큐에 삽입
				q.push(n);			// 큐에 삽입되는 순간 4보다 1이 우선이라 앞으로 당겨짐
			}
		}
	}

	for (int k : ans) {
		cout << k << " ";
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);	// 4 = { 2 }, 3 = { 1 } 
		cnt[b]++;			    // cnt[2] = 1, cnt[1] = 1
	}

	fuck();
}