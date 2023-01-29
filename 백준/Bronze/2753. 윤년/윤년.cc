#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;

	if (!(n % 4)) {
		if ((n % 100 != 0) || (n % 400 == 0)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
