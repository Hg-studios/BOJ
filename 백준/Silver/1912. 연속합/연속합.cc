#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
d[i] : i번까지 왔을 때 최대 연속된 수의 합
       i번째 요소는 들어갈 수도 들어가지 않을 수도 있음
*/
int d[100005];
int s[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    for(int i=1; i<=n; i++) cin>>s[i];

    d[1] = s[1];
    for(int i=2; i<=n; i++){
        d[i] = max(s[i], d[i-1]+s[i]);
    }

    cout<< *max_element(d+1, d+n+1);

    return 0;
}