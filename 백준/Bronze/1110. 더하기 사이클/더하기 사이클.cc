#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int cycle=0;
    int init=n;
    while(1){
        cycle++;
        n = (n%10)*10 + (n%10+n/10)%10;
        
        if(init==n) break;
    }
    cout<<cycle;
}