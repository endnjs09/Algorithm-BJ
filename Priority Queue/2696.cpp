#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int M;
        cin >> M;

        cout << (M + 1) / 2 << '\n';

        priority_queue<int, vector<int>, less<int>> p;      // 최대힙 (작은 수 그룹)
        priority_queue<int, vector<int>, greater<int>> q;   // 최소힙 (큰 수 그룹)

        int count = 0;
        for (int j = 1; j <= M; j++) {
            int num;
            cin >> num;

            if (j % 2 != 0) {
                p.push(num);
            }
            else q.push(num);

            if ((!p.empty() && !q.empty()) && p.top() > q.top()) {
                // 작은 수 그룹의 최대가 큰 수 최소 보다 크면 교체함
                int tmp1 = p.top();
                int tmp2 = q.top();

                p.pop();
                q.pop();

                p.push(tmp2);
                q.push(tmp1);
            }

            if (j % 2 != 0) {
                count++;
                cout << p.top();

                if (count % 10 == 0) {
                    cout << '\n';
                }
                else if (j != M) {
                    cout << " ";
                }
            }
        }

        if (count % 10 != 0) cout << '\n';
    }
}