#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, W, t = 0;
    cin >> N >> W;
    
    t += N * 10;

    if (N >= 3) {
        t += 20;
        if (N == 5) {
            t += 50;
        }
    }

    if (W > 1000) {
        t -= 15;
        if (t < 0) t = 0;
    }

    cout << t;

}