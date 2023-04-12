#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n; 
int s[1005]; //값 저장
int d[1005]; //dp 저장
int way[1005]; //경로 저장, 0으로 초기화됨

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>s[i];
        d[i]=1; //자기자신만 포함될 때 가장 작은 dp값
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(s[j]>=s[i]) continue;

            if(d[i]<d[j]+1){
                d[i] = d[j]+1;
                way[i] = j;
            }
            
        }
    }

    //가장 긴 증가하는 부분을 갖는 인덱스를 찾음
    int mx=-1, mxidx=-1;
    for(int i=1; i<=n; i++){
        if(mx<d[i]) {
            mx=d[i];
            mxidx=i;
        }
    }

    deque<int> deq;
    deq.push_back(s[mxidx]);

    int cur = way[mxidx];
    while(cur!=0){
        deq.push_front(s[cur]);
        cur = way[cur];
    }

    cout<<*max_element(d+1, d+1+n)<<'\n';
    for(auto i : deq) cout<<i<<" ";
}