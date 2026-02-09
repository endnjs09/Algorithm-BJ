#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define SIZE 100001
using namespace std;

int d[SIZE];

void f(int start, int end) {
    for (int i = 0; i < SIZE; i++) {
        d[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 시간, 위치
    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty()) {
        int time = pq.top().first;     // 시간
        int current = pq.top().second;   // 위치
        pq.pop();

        if (current == end) {
            cout << time;
            return;
        }

        if (d[current] < time) continue;

        int next[] = { current * 2, current + 1, current - 1 };

        for (int i = 0; i < 3; i++) {
            int nx = next[i];   // 다음 위치 (2*x가 먼저)
            int next_time;      // 다음 위치로 이동했을 때 시간
            
            if (i == 0) next_time = time + 0;   // 2x면 시간 + 0
            else next_time = time + 1;          // 나머지 +1

            if (nx >= 0 && nx < SIZE) {
                if (next_time < d[nx]) {
                    d[nx] = next_time;
                    pq.push({ next_time, nx }); // pq = {(0, 10), (1, 6), (1, 4)}
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K;
    cin >> N >> K;

    f(N, K);
}