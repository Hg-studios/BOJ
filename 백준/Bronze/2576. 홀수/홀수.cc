#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	
	int min = 999, res = 0, n;

	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2) {
			res += n;
			if (n < min) min = n;
		}
	}

	if (!res) cout << -1;
	else cout << res << '\n' << min;

	return 0;
}