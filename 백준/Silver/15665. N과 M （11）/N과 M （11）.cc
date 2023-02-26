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

	//isused를 쓰는 이유는 이미 쓴 수(인덱스도 같은 말그대로 "같은" 수)를 또다시
	//뽑지 않아서 중복을 피하기 위함임
	//tmp를 쓰는 이유는 input에 같은 수가 들어오게 된 상황에서, 같은 단계에서
	//값이 같은 수를 쓰지 않기 위함임
	//그래서 중복순열을 만들기 않기 위해서 tmp!=input[i]는 그대로 살려두면서
	//isused배열 확인은 없애면 이 문제를 풀 수 있음 
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		if (tmp!=input[i]) { //tmp와 이번 수가 같다면 중복수열임 
			tmp = input[i]; //tmp는 input수를 저장해야 다음에 뽑힐 수와 비교하므로 
			arr[k] = i; //i의 범위를 지금 뽑히는 수를 기준으로 지정해줘야하므로 인덱스 저장
			//isused[i] = 1;
			func(k + 1);
			//isused[i] = 0;
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