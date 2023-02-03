#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack <int> s;
	int n, sum = 0;;
	cin >> n;
	
	while (n--) {
		int x; cin >> x;

		if (x == 0) {
			if (!s.empty()) s.pop();
		}
		else if (x > 0) {
			s.push(x);
		}
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << '\n';

	return 0;
}