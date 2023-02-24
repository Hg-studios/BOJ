#include <iostream>
using namespace std;

//constexpr int MAX
char arr[3072][6143]; //행은 3*2^10이 최대이며, 열은 3072*2-1이 최대임

void star(int r, int c) { //r,c을 맨 위의 꼭짓점으로 하는 별을 찍어줌 
	//첫번째줄 (꼭직점에 * 1개)
	arr[r][c] = '*';

	//두번째줄 (* 2개)
	arr[r + 1][c - 1] = '*';
	arr[r + 1][c + 1] = '*';

	//세번째 줄 (* 5개)
	for (int i = 0; i < 5; i++) {
		arr[r + 2][c - 2 + i] = '*';
	}
}

void func(int r, int c, int k) {
	if (k == 3) { // 한 변의 길이가 3이 되면 별을 찍어줌
		star(r, c);
		return; //return을 해주어야 밑에 코드를 실행하지 않고 여기서 잘 마치게 됨
	}

	int half = k / 2;

	func(r, c, half); //첫번째 삼각형의 꼭짓점
	func(r + half, c - half, half); //두번째 삼각형의 꼭짓점
	func(r + half, c + half, half); //세번째 삼각형의 꼭짓점 
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' '; //배열에 공백으로 넣어줘야함 
		}
	}
	
	func(0, n-1, n); //가장 큰 삼각형부터 시작해서 별찍기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}