#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[100];
int V[100];
int dp[101][101010];

int go(int i, int w) { //i번째 물건, 현재까지의 무게w
	//top-down방식
	//i번째 물건까지 검사했을 때 무게는 w이고 go함수의 반환값이 가치값
	
	if (dp[i][w] > 0) return dp[i][w]; //2. 배열에 저장된 값이 있으면 리턴
	if (i == N) return 0; //1. 재귀 break condition
	//if (dp[i][w] > 0) return dp[i][w]; //2. 배열에 저장된 값이 있으면 리턴
	
	//3. 저장된 값이 없다면, 값 구하기 위한 점화식 세우기
	//i번째 물건을 포함시키거나(n1) 미포함시키거나(n2)
	int n1=0, n2=0; 

	if (w + W[i] <= K) n1 = V[i] + go(i + 1, w + W[i]); //포함
	n2 = go(i + 1, w); //미포함

	return dp[i][w] = max(n1, n2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin>> W[i] >> V[i];
	}

	cout << go(0, 0);

	return 0;
}