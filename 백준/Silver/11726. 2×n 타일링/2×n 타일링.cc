#include <iostream>
#include <algorithm>
using namespace std;

//d[i] : i번째 타일을 채우는 방법의 수
int d[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    //초기값 설정
    d[1] = 1; 
    d[2] = 2;

    for(int i=3; i<=n ;i++){
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }

    cout << d[n];

    return 0;
}