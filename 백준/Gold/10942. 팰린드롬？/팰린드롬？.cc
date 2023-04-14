#include <iostream>
#include <algorithm>
using namespace std;

int a[2005];
int d[2005][2005]; //d[a][b]=k : a~b까지 팰린드롬이라면 1, 아니라면 0

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n; i++){
        d[i][i]=1; //자기자신만은 팰린드롬임
        if(a[i-1]==a[i]) d[i-1][i]=1; //차이가 1 나는 애들 처리해줌
    }

    for(int gap=2; gap<n; gap++){ //차이가 2 나는 애들부터 n-1 까지 처리해줌
        for(int i=1; i<=n-gap; i++){
            int s=i, e=i+gap; //시작점은 i이고, 끝점은 i+gap임
            //시작점과 끝점이 같아야하고
            //시작점과 끝점을 제외한 가운데 숫자가 팰린드롬이어야함
            if(a[s]==a[e] && d[s+1][e-1]) d[s][e]=1; 
        }
    }

    int tc; cin>>tc;
    while(tc--){
        int s,e; 
        cin>>s>>e;
        cout<<d[s][e]<<'\n';
    }

    return 0;
}