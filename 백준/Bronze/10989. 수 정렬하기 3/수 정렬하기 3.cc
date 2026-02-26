#include <iostream>
using namespace std;

// 숫자의 등장 횟수를 저장 배열
int counting[10001] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 숫자가 등장할 때마다 해당 숫자의 카운트만 올림
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        counting[num]++;
    }

    // 기록된 횟수만큼 숫자를 출력
    for (int i = 1; i <= 10000; i++) {
        if (counting[i] > 0) {
            for (int j = 0; j < counting[i]; j++) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}