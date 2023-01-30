#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[10] = {};
	int n; cin >> n;

	while (n > 0) {
		arr[n % 10]++;
		n /= 10;
	}

	//6,9 두 카드는 서로 같은 것으로 취급 가능하므로 
	//699라면 세트2개가 필요하므로 /2값과 %2값을 더해주면 
	//6,9에 필요한 세트의 개수가 나옴
	arr[6] = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2; 

	int max = -1, maxIdx=-1;
	for (int i = 0; i < 10; i++) {
		if (i != 9) { //arr[9]는 이미 계산되어 arr[6]에 저장함
			if (max < arr[i]) {
				max = arr[i];
				maxIdx = i;
			}
		}
		
	}
	
	cout << max;

	return 0;
}