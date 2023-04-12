#include <iostream>
#include <algorithm>
using namespace std;

int d[20]; //d[i]=k : i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익
int t[20]; //상담일 수
int p[20]; //상담액

int main(){
    int n; cin>>n;

    for(int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
    }

    for(int i=n; i>=1; i--){
        //i번째 일에 상담을 할 수 있는 경우
        if(i+t[i]-1<=n){
            //상담을 할 때와 안할 때를 비교하여 큰 값을 넣어줌
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        //i번째 일에 상담을 할 수 없는 경우
        else d[i]=d[i+1];
    }
    cout<<*max_element(d+1, d+n+1); //1-indexed이므로!!
}