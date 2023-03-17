#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
1. 테이블 정의하기
d[i][j] : i번째 수까지 왔을 때 이친수의 개수
          단, j는 현재 내 수를 의미함 (0 or 1)
2. 점화식 세우기
d[i][0] = d[i-1][0] + d[i-1][1]
d[i][1] = d[i-1][0]

답은 d[i][0]+d[i][1]이 됨
3. 초기값 설정하기
d[1][0] = 0; -> 이친수는 맨앞에 0이 올 수 없음 
d[1][1] = 1;
*/
long long d[93][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    d[1][0]=0;
    d[1][1]=1;

    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    cout<<d[n][0]+d[n][1];

    return 0;
}