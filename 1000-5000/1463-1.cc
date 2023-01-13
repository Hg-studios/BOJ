#include <iostream>
#include <string.h>
using namespace std;

int D[1010101];

int f(int n) {
	//재귀문 탈출조건
	if (n == 1) return 0; //1을 만드는 것이므로 1에 도착하면 끝
	//해당 값이 있는지 없는지 확인
	//있으면 바로 리턴해주고
	if (~D[n]) return D[n];
	//없다면 값을 구하기 위해 식 구현 해주면 됨 
	D[n] = f(n - 1) + 1;
	if (n % 2 == 0) D[n] = min(D[n], f(n / 2) + 1);
	if (n % 3 == 0) D[n] = min(D[n], f(n / 3) + 1);

	return D[n];
}

int main() {
	int n; cin >> n;
	memset(D, -1, sizeof(D));

	cout << f(n);

	return 0;
}