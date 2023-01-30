#include <iostream>
#include <algorithm>
using namespace std;

int arr[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 21; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int a, b; cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}

	for (int i = 1; i < 21; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
