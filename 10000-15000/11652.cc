#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	//현재 세고있는 수의 개수는 cnt에, 현재까지 가장 많이 나온 수의 개수는 mxcnt에 저장
	int cnt = 0, mxcnt = 0; 
	//현재 가장 많이 나온 수를 저장 
	long long mxn = 0; 

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cnt++;
		}
		else if (arr[i - 1] == arr[i]) {
			cnt++;
		}
		else { //첫번째 인덱스도 아니면서 앞수와 다른수가 나온 경우
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxn = arr[i - 1];
			}
			cnt = 1; //cnt초기화
		}
	}

	//마지막카운팅된 수를 처리해줘야함
	if (cnt > mxcnt) mxn = arr[n - 1];

	cout << mxn;

	return 0;
}