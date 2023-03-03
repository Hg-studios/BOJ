#include <iostream>
#include <algorithm>
using namespace std;

//int arr[10]; //4 2라면 0,0,1,1로 채워둠
int num[10]; //수를 입력받음 
int tmp[10]; //뽑았던 수 저장 

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//입력받고 오름차순으로 정렬해줌
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);

	//순열 만들기
	do {
		bool flag = 0;
		for (int i = 0; i < m; i++) {
			if (num[i] != tmp[i]) {
				flag = 1;
				break;
			}
		}
		if (!flag) continue;

		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
			tmp[i] = num[i];
		}
		cout << '\n';
	} while (next_permutation(num,num+n));

	return 0;
}