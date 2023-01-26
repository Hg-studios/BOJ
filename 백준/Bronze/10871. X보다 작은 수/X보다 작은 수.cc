#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x; cin >> n >> x;
	//int arr[10000];
	int tmp;
	for (int i = 0; i < n; i++) {
		//cin >> arr[i];
		cin >> tmp;
		if (tmp < x) cout << tmp << ' ';
	}
	return 0;
}
