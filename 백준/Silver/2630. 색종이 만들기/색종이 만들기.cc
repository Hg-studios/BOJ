#include <iostream>
using namespace std;

constexpr int MAX = 130;
int arr[MAX][MAX];
int cnt0, cnt1;

void func(int r, int c, int k) {
	bool flag=1;

	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			if (arr[r][c] != arr[i][j]) flag = 0;
		}
	}

	//색이 다른 경우
	if (!flag) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(r + i * k / 2, c + j * k / 2, k / 2);
			}
		}
	}
	//색이 모두 같은 경우
	else {
		if (arr[r][c] == 0) cnt0++;
		else cnt1++;
		return;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);

	cout << cnt0 << '\n';
	cout << cnt1 << '\n';

	return 0;
}