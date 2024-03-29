#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int input[10];
//bool isused[10];
int n, m;

void func(int k) {
	if (k == m) { //모든 수를 다 넣은 경우이므로 끝임 
		for (int i = 0; i < m; i++) {
			cout << input[arr[i]] << " ";
		}
		cout << '\n';
		return;
	}

	int st = 0;
	if (k != 0) st = arr[k - 1]; //k-1번째에 선택된 수를 포함해서 큰 수만 검사 

	for (int i = st; i < n; i++) {
		//isused를 쓰는 이유가 중복확인을 위한 것이므로 isused확인을 안해주면 됨
		//if (!isused[i]) {
			arr[k] = i; //저장될 input의 인덱스를 arr에 저장함
			//isused[i] = 1;
			func(k + 1);
			//isused[i] = 0;
		//}
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