#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//우선, 1로 채워놓기
	fill(arr, arr + n, 1);

	//그 다음 m개만큼 앞에 0으로 채우기
	for (int i = 0; i < m; i++) {
		arr[i] = 0;
	}

	//조합 만들기
	do {
		for (int i = 0; i < n; i++) {
			if(arr[i]==0)
				cout << i+1 << " ";
		}
		cout << '\n';
	} while (next_permutation(arr,arr+n));

	return 0;
}