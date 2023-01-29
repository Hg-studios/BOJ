#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int arr[3];	
	for (int i = 0; i < 3; i++) cin >> arr[i];

	int& a = arr[0];
	int& b = arr[1];
	int& c = arr[2];

	if (a == b && b == c) cout << 10000 + a * 1000;
	else if (a == b) cout << 1000 + a * 100;
	else if (b == c) cout << 1000 + b * 100;
	else if (c == a) cout << 1000 + c * 100;
	else {
		sort(arr, arr + 3);
		cout << arr[2] * 100;
	}

	return 0;
}
