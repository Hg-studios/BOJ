#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	
	string str = "DCBAE";
	int arr[4]; 

	for (int i = 0; i < 3; i++) {
		int cnt = 0;  //1 개수 세기
		for (int j = 0; j < 4; j++) {
			cin >> arr[i];
			if (arr[i]) cnt++;
		}
		cout << str[cnt] << '\n';
	}

	return 0;
}