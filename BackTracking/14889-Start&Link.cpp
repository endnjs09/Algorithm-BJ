#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n, minValue = INT_MAX;;

void teamDiff(vector<vector<int>>& s, vector<bool>& visited, int index, int count) {
	int sumA = 0, sumB = 0, diff = 0;
	if (count == n / 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] == true && visited[j] == true)
					sumA += s[i][j];
				else if (visited[i] == false && visited[j] == false)
					sumB += s[i][j];
			}
		}
		diff = abs(sumA - sumB);
		minValue = min(minValue, diff);
		return;
	}

	for (int i = index; i < n; i++) {
		visited[i] = true;
		teamDiff(s, visited, i + 1, count + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	vector<vector<int>> s(n, vector<int>(n, 0));
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	teamDiff(s, visited, 0, 0);

	cout << minValue;
}

