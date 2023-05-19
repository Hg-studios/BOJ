#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	int t = 10;
	for (int tc = 1; tc <= t; tc++) {
		//입력받기
		int n; cin >> n;

		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
		}

		int m; cin >> m;
		while (m--) {
			char inst; cin >> inst;
			if (inst == 'I') {
				int x, y; cin >> x >> y;

				vector<int> v2;
				while (y--) {
					int k; cin >> k;
					v2.push_back(k);
				}
				v.insert(v.begin() + x, v2.begin(), v2.end());
			}
			else if (inst == 'D') {
				int x, y; cin >> x >> y;
				while (y--) {
					v.erase(v.begin() + x);
				}
			}
			else if (inst == 'A') {
				int y; cin >> y;
				while (y--) {
					int k; cin >> k;
					v.push_back(k);
				}
			}
		}
		cout << "#" << tc << " ";
		int cnt = 0;
		for (auto i : v) {
			cnt++;
			if (cnt > 10) break;
			cout << i << " ";
		}
		cout << '\n';
	}
}