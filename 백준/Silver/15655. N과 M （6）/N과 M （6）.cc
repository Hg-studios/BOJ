#include <iostream>
#include <algorithm>
using namespace std;

int arr[10]; //4 2라면 0,0,1,1로 채워둠
int num[10]; //수를 입력받음 

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//입력받고 오름차순으로 정렬해줌
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);

	//우선, arr배열을 모두 1로 채움
	for (int i = 0; i < n; i++) arr[i] = 1;
	//앞에 m개만 0으로 채움
	for (int i = 0; i < m; i++) arr[i] = 0;

	//조합 만들기
	do {
		for (int i = 0; i < n; i++) {
			if(!arr[i])
				cout << num[i] << " ";
			
		}
		cout << '\n';
	} while (next_permutation(arr,arr+n));

	return 0;
}