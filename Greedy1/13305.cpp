#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	vector<int> d, v;	// 도로 길이, 도시(기름값)
	cin >> n;

	for (int i = 0; i < n - 1; i++) {	// 도로 길이
		int a;
		cin >> a;
		d.push_back(a);
	}
	for (int i = 0; i < n; i++) {	// 리터당 가격
		int b;
		cin >> b;
		v.push_back(b);
	}

	int i = 0;
	long long min = v[0], r = 0;	// 비용
	while (i != n - 1) {
		r += min * d[i];	// 기름값 x 거리

		if (v[i + 1] < min)	// 다음 도시의 기름 값이 현재 도시의 기름 값보다 쌈
			min = v[i + 1]; // 기름값 갱신

		i++;
	}

	cout << r;
}