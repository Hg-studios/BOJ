#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n; cin >> n;

	while (n--) {
		string str; cin >> str;

		if (str == "push") {
			int x; cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if(str == "back") {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}