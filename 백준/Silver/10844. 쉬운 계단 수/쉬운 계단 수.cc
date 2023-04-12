#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[102][10]; //d[a][b]=k : 길이가 a인 계단수의 마지막 숫자가 b인 계단수가 총 c개이다.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=9; i++) d[1][i]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j==0) d[i][j] = d[i-1][1] % 1000000000;
            else if(j==9) d[i][j] = d[i-1][8] % 1000000000;
            else d[i][j] = (d[i-1][j-1]+d[i-1][j+1]) % 1000000000;
        }
    }

    int ans=0;
    //길이가 n인 계단수 출력
    for(int i=0; i<=9; i++){
        ans = (ans+d[n][i])%1000000000;
    }

    cout<<ans;

    return 0;
}