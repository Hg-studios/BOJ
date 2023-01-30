#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10]; fill(arr, arr + 10, 0);
	int a, b, c; cin >> a >> b >> c;
	int res = a * b * c;

	while (res > 0) {
		arr[res % 10]++;
		res /= 10;
	}

	for (int a : arr) cout << a << '\n';

	return 0;
}