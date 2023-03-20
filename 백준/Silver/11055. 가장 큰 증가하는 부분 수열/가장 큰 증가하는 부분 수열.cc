#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int d[1003]; //d[i] : i번 인덱스까지 가장 큰 부분 수열의 합
int s[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=1; i<=N; i++) cin>>s[i];

    for(int i=1; i<=N; i++){
        d[i]=s[i]; //부분수열 중 자신만 선택했을 때가 가장 작은 값이므로
        
        for(int j=1; j<i; j++){
            if(s[j]<s[i]){
                d[i] = max(d[i], d[j]+s[i]);
            }
        }
    }

    cout<<*max_element(d+1, d+N+1);

    return 0;
}