#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, maxValue = INT_MIN, minValue = INT_MAX;
vector<int> v;

void insert(int index, int sum, int plus, int minus, int mul, int div) {

	if (index == n) {
		maxValue = max(maxValue, sum);
		minValue = min(minValue, sum);
		return;
	}

	if (plus > 0)
		insert(index + 1, sum + v[index], plus - 1, minus, mul, div);
	if (minus > 0)
		insert(index + 1, sum - v[index], plus, minus - 1, mul, div);
	if (mul > 0)
		insert(index + 1, sum * v[index], plus, minus, mul - 1, div);
	if (div > 0)
		insert(index + 1, sum / v[index], plus, minus, mul, div - 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}


	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	insert(1, v[0], plus, minus, mul, div);

	cout << maxValue << '\n' << minValue;
}

