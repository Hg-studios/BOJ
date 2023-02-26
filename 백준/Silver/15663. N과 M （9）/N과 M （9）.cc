#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int input[10]; //input에 주어진 n개의 수를 저장함
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

	//Q : 예제2에서 9 9는 어떻게 나오는 거임??...
	//A : func(k+1)로 들어가게 되면 tmp가 또 하나 생김. 그리고 걔는 0으로 초기화되고..
	//	  그래서 같은 레벨에 있는 즉, 같은 k 레벨끼리만 중복을 검사하게 되는 것임

	int tmp = 0; //중복 수열인지 확인하기 위한 변수 

	for (int i = 0; i < n; i++) {
		//이전 수열의 마지막항과 새로운 수열의 마지막 항이 같으면 중복수열임
		//그러니깐 같은 k레벨에서 같은 수가 뽑히면 안되기 때문에 k단계에 tmp라는
		//변수를 두고 i가 0부터 n까지 움직일 때 전에 저장되었던 수를 저장해둠 
		if (!isused[i] && tmp!=input[i]) {
			tmp = input[i];
			arr[k] = input[i]; //저장될 input의 인덱스를 arr에 저장함
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

	//input을 받음 
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	
	}
	//input배열 정렬해줘야함 
	sort(input, input + n);

	func(0);

	return 0;
}