#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    int rem, x=b;
    while(1){
        rem = x%10;
        x/=10;
        if(x<1&&rem<1) break;

        cout<<a*rem<<'\n';
    }

    cout<<a*b;    
}
