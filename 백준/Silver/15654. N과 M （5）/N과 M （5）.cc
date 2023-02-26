#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int input[10];
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

	//N와 M(1)과 다른 점은 i가 1~n까지가 아니라 0~n-1를 쓴다는 것임
	//당연함 N와M(1)은 따로 input배열을 만들지 않고 for문에 쓰인 i 인덱스 값을
	//썼기 때문임 그러나 이 문제는 input이 따로 있고 이 input배열의 인덱스는 
	//0부터 n-1에 저장되어있기 때문임 
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = input[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	//input배열 정렬해줘야함 
	sort(input, input + n);

	func(0);

	return 0;
}