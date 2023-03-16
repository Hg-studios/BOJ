#include <iostream>
#include <algorithm>
using namespace std;

//d[i] : 1~i 원소들의 합
int d[100005]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin>>n>>m;

    d[0] = 0;

    int tmp;
    for(int i=1; i<=n; i++){
        cin>>tmp;
        d[i] = d[i-1]+ tmp;
    }

    while(m--){
        int i ,j; cin>>i>>j;

        cout<<d[j]-d[i-1]<<'\n';
    }

    return 0;
}