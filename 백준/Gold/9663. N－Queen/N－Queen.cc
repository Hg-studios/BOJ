#include <iostream>
using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt, n;

void func(int cur) { //cur번째 row에 말을 배치할 예정임
	if (cur == n) { //n개의 퀸을 놓는데 성공한 것임
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) { //(cur, i)에 퀸을 놓을 예정임
		//열이나 대각선 중에 충돌이 있다면 놓지 못함 
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;

		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);
	cout << cnt;
	
	return 0;
}