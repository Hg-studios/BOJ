#include <iostream>
#include <algorithm>
using namespace std;

int input[15]; //k개의 수를 뽑을 배열 
int arr[8]; //k개 중 6개가 저장될 배열, arr배열에 input인덱스를 저장함
bool isused[15]; //그 수가 사용되었는지 검사하는 배열
int k;

void func(int cur) {
	if (cur == 6) { //6개를 다 뽑았다면 출력해줌
		for (int i = 0; i < 6; i++) {
			cout << input[arr[i]] << " ";
		}
		cout << '\n';

		return;
	}

	//cur-1에 뽑힌 수보다 큰 수만 뽑고자 하므로 
	int st = 0;
	if (cur != 0) st = arr[cur - 1] + 1;

	for (int i = st; i < k; i++) { //input이 사용되었는지를 하나씩 확인하고 뽑음 
		if (!isused[i]) {
			arr[cur] = i; //저장할 input 인덱스 저장
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> k;

		if (k == 0) break;

		fill(input, input + 15, 0);
		fill(arr, arr + 8, 0);
		fill(isused, isused + 15, 0);

		for (int i = 0; i < k; i++) {
			cin >> input[i];
		}

		func(0);
		cout << '\n';
	}
	return 0;
}