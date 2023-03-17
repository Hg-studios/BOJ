#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int s[505][505];
int d[505][505];
/*
1. 테이블 정하기
d[i][j] : i행j렬까지 왔을 때 경로에 있는 수의 최대값
2. 점화식 구하기
d[i][j] = max(d[i-1][j-1], d[i-1][j]) + s[i][j]
3. 초기값 설정
d[1][1]=s[1][1];
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin>>s[i][j];
        }
    }

    //초기값 설정
    d[1][1]=s[1][1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i][j] = max(d[i-1][j-1],d[i-1][j])+s[i][j];
        }
    }

    int mx=-1;
    for(int i=1; i<=n; i++) mx = max(mx, d[n][i]);

    cout<<mx;
    
    return 0;
}