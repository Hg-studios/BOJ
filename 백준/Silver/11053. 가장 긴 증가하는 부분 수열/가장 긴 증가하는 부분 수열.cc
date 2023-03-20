#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int d[1003]; //d[i]=k : i번째까지 증가하는 부분 수열의 최대 길이
int s[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>s[i];
        d[i]=1; //처음에는 길이가 자기 자신만 포함이므로 1임
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            if(s[j]<s[i]) d[i] = max(d[i], d[j]+1);
        }
    }

    cout<<*max_element(d+1, d+N+1);
}