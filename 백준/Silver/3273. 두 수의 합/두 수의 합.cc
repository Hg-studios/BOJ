#include <iostream>
using namespace std;

int arr[1000001];
//각 자연수의 존재 여부를 저장하는 배열
//아래 코드에서 x-arr[i]이 1000000보다 큰 경우를 
//예외처리하지 않기 위해 최대인 200만으로 잡음
bool check[2000001];
int n, x, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> x;

	for (int i = 0; i < n; i++) {
		//check 배열값이 1일 때만 if문으로 들어가게 되는데
		//그 인덱스가 음수가 나오면 런타임에러가 나므로 0이상인지 확인함
		if (x - arr[i] > 0 && check[x - arr[i]]) cnt++;
		//한 쌍 ai, aj가 있을 때, ai를 체크하고
		//ai일 때 count되지 않다가 
		//aj일 때 x-arr[i]인 값일 때 count됨
		check[arr[i]] = 1; 
	}

	cout << cnt;

	return 0;
}