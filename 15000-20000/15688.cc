#include <iostream>
#include <algorithm>
using namespace std;

const int MXN = 2'000'000, HALF = MXN / 2;
int arr[MXN+2];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int t;
	while (n--) {
		cin >> t;
		arr[t + HALF]++;
	}

	for (int i = 0; i <= MXN; i++) {
		while (arr[i]) {
			cout << i - HALF << '\n';
			arr[i]--;
		}
	}

	return 0;
}