#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h,m,c; cin>>h>>m>>c;

    h += (m+c)/60;
    m = (m+c)%60;
    if(h>=24) h-=24;

    cout<<h<<" "<<m;
}