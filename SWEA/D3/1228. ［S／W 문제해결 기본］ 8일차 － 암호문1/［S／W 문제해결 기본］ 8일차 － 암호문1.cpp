#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		vector<int> v;

		int n; cin >> n;
		while (n--) {
			int x; cin >> x;
			v.push_back(x);
		}

		int m; cin >> m;
		while (m--) {
			char c; cin >> c;
			int pos, k; 
			cin >> pos >> k;
			for (int i = 0; i < k; i++) {
				int x; cin >> x;
				v.insert(v.begin() + pos + i, x);
			}
		}

		cout << "#" << tc << " ";
		int cnt = 0;
		for (auto i : v) {
			cnt++;
			if (cnt > 10) break;
			cout << i<<" ";
		}
		cout << '\n';
	}
    return 0;
}