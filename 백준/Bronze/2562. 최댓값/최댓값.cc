#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int max = -1, idx = -1;
	for (int i = 1; i <= 9; i++) {
		int n; cin >> n;
		if (max < n) {
			max = n;
			idx = i;
		}
	}

	cout << max << '\n' << idx;

	return 0;
}
