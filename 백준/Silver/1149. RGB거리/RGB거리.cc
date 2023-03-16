#include <iostream>
#include <algorithm>
using namespace std;

//d[i][j] : i번째 집까지 색칠하는데 비용의 최솟값
//d[i][0] : 단, i번째 집의 색깔이 빨강으로 칠하는 경우
//d[i][1] : 단, i번째 집이 초록
//d[i][2] : 단, i번째 집이 파랑
int d[1001][5];
int R[1001], G[1001], B[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    for(int i=1; i<=n; i++){
        cin >> R[i];
        cin >> G[i];
        cin >> B[i];
    }

    //초기값 설정
    d[1][0] = R[1];
    d[1][1] = G[1];
    d[1][2] = B[1];

    for(int i=2; i<=n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + R[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + G[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + B[i];
    }

    cout<< min({d[n][0], d[n][1], d[n][2]});
}