#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	vector<string> minus;

	while (1) {
		int pos = s.find('-');	
		if (pos == string::npos) {
			minus.push_back(s);
			break;
		}
		string t = s.substr(0, pos);
		minus.push_back(t);
		s = s.substr(pos + 1);
	}
	// 50 - 60 + 40 >> { 50, 60 + 40 }

	vector<int> res;
	for (string p : minus) {
		int sum = 0;
		while (1) {
			int pos = p.find('+');
			if (pos == string::npos) {
				sum += stoi(p);
				break;
			}

			string t = p.substr(0, pos);
			sum += stoi(t);
			p = p.substr(pos + 1);
		}
		res.push_back(sum);	// 50, 60, 40
	}

	int ans = res[0];
	for (int i = 1; i < res.size(); i++) {
		ans -= res[i];
	}

	cout << ans;
}

