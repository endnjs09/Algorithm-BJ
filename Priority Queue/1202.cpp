#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;    // 보석
    priority_queue<int, vector<int>, greater<int>> q;   // 가방
    priority_queue<int, vector<int>, less<int>> r;

    for (int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        p.push({ M, V });
    }

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        q.push(C);
    }

    long long ans = 0;
    while (!q.empty()) {
        int temp = q.top();
        q.pop();

        while (!p.empty() && temp >= p.top().first) {
            r.push(p.top().second);
            // 그 보석의 가격을 큐에 넣기
            p.pop();
        }

        if (!r.empty()) {
            ans += r.top();
            r.pop();
        }
    }

    cout << ans;
}