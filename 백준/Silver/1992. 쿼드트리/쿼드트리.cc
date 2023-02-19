#include <iostream>
using namespace std;

constexpr int MAX = 66;
string arr[MAX];

//문제 이해를 잘못함,, 꼭 4등분으로 나누는 것이 아니고 
//다 같지 않으면 그제서야 4등분으로 나눔ㅇㅇ!
//그리고 (0) 혹은 (1) 이 아니고 4등분되면은 ( ) 가 생기는 것임
//1780.종이의개수 와 2630.색종이만들기 와 똑같은 문제인데 
//왜.. 이건 다르게 느껴진거지? 

//해당 영상이 하나의 숫자로 이뤄져있는지 확인하는 함수 
bool check(int r, int c, int k) {
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			if(arr[r][c]!=arr[i][j])
			return 0;
		}
	}
	return 1;
}

void func(int r, int c, int k) {
	//수가 모두 같으면 그것을 출력
	if (check(r, c, k)) {
		cout << arr[r][c];
		return;
	}

	//수가 0, 1 섞여있다면
	int half = k / 2;
	cout << "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(r + i * half, c + j * half, half);
		}
	}
	cout << ")";
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	func(0, 0, n);

	return 0;
}