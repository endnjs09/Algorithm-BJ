#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SIZE = 501;
vector<int> adj[SIZE];
bool visited[SIZE];
int p[SIZE];

bool f(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    bool isTree = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int next : adj[current]) {
            if (!visited[next]) {
                p[next] = current;
                visited[next] = true;
                q.push(next);
            }
            else {
                if (next != p[current]) isTree = false;
            }
        }
    }
    return isTree;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 1;
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int t_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (f(i)) t_cnt++;
            }
        }
        
        if (t_cnt > 1) cout << "Case " << c << ": " << "A forest of " << t_cnt << " trees." << '\n';
        else if (t_cnt == 1) cout << "Case " << c << ": There is one tree." << '\n';
        else cout << "Case " << c << ": No trees." << '\n';
        c++;
    }
}