#include <iostream>
using namespace std;

int arr[10];
bool isused[10];
int n, m;

void func(int k) {
	if (k == m) { //모든 수를 다 넣은 경우이므로 끝임 
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	int st = 1;
	if (k != 0) st = arr[k - 1]; //이전에 뽑힌 것을 포함한 크기부터 뽑을 수 있음

	for (int i = st; i <= n; i++) {
		//if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		//}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);

	return 0;
}