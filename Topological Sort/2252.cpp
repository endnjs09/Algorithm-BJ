#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;	// 학생 수, 비교 횟수
int cnt[100001];	// 진입 차수
vector<int> adj[100001];

void fuck() {
	vector<int> ans;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {	// 진입 차수가 0이면
			q.push(i);		// 큐에 삽입 (1, 2가 들어감)
		}
	}

	while (!q.empty()) {
		int current = q.front();	// current = 1
		q.pop();					// 1 제거
		ans.push_back(current);		// ans에 1 추가

		for (int n : adj[current]) { // n : adj[1] = {3}
			cnt[n]--;				 // cnt[3]--

			if (cnt[n] == 0) {
				q.push(n);
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

		adj[a].push_back(b);	// 1 = { 3 }, 2 = { 3 } 
		cnt[b]++;				// cnt[3] = 2
	}

	fuck();
}