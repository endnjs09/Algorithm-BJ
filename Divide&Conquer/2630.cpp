#include <iostream>
#include <vector>
using namespace std;

int w_count = 0, b_count = 0;

void function_C(vector<vector<int>>& arr, int x, int y, int size) {
    int first = arr[x][y];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[x + i][y + j] != first) {

                function_C(arr, x, y, size / 2);
                function_C(arr, x + size / 2, y, size / 2);
                function_C(arr, x + size / 2, y + size / 2, size / 2);
                function_C(arr, x, y + size / 2, size / 2);

                return;
            }
        }
    }

    if (first == 0) w_count++;
    else b_count++;

}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    function_C(v, 0, 0, N);

    cout << w_count << '\n' << b_count;
}