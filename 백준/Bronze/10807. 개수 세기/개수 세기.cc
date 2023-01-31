#include <iostream>
using namespace std;

int arr[201]; //-100~100 이므로 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,v; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp + 100]++;
	}

	cin >> v;
	cout << arr[v + 100];

	return 0;
}