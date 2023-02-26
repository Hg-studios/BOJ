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
			cout << input[arr[i]] << " ";
		}
		cout << '\n';
		return;
	}

	int tmp = 0; //이전 수열의 마지막 수를 저장할 변수 
	int st = 0; //앞 문제들을 풀 때와 같이 나와 같거나 큰 수들만 뽑으려고 st변수 선언
	if (k != 0) st = arr[k-1]+1; 

	for (int i = st; i < n; i++) {
		if (!isused[i] && tmp!=input[i]) { //tmp와 이번 수가 같다면 중복수열임 
			tmp = input[i]; //tmp는 input수를 저장해야 다음에 뽑힐 수와 비교하므로 
			arr[k] = i; //i의 범위를 지금 뽑히는 수를 기준으로 지정해줘야하므로 인덱스 저장
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