#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
1. 테이블 정하기
d[i] : 2xi 직사각형을 채우는 방법의 수
2. 점화식 세우기
d[i] = d[i-1] + d[i-2]*2
3. 초기값 설정
d[1] = 1, d[2]=3;
*/
int d[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    //초기값 설정
    d[1]=1, d[2]=3;

    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2]*2)%10007;
    }

    cout<<d[n];

    return 0;
}