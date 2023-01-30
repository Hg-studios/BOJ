#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i-1; j++) cout << " ";
		for (int j = 1; j <= 2 * (n - i) + 1; j++) cout << "*";
		cout << '\n';
	}

	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= n - i - 1; j++) cout << " ";
		for (int k = 1; k <= 2 * i + 1; k++)cout << "*";
		cout << '\n';
	}
	return 0;
}
