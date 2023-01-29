#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
		
	int arr[2];
	cin >> arr[0] >> arr[1];
	sort(arr, arr + 2);

	

	if (arr[1]-arr[0]>1) {
		cout << arr[1] - arr[0] - 1 << '\n';

		for (int i = arr[0] + 1; i < arr[1]; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << 0;
	}
	
	return 0;
}