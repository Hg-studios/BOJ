#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h,m,s,d;
    cin>>h>>m>>s>>d;

    s+=d;
    if(s>59){
        m+=(s/60);
        s%=60;
    }
    if(m>59){
        h+=(m/60);
        m%=60;
    }
    if(h>23){
        h%=24;
    }
    
    cout<<h<<" "<<m<<" "<<s;
}