#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	cout << n + m << '\n'
		<< n - m << '\n'
		<< n * m << '\n'
		<< n / m << '\n'
		<< n % m;
	return 0;
}