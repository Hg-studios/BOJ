#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h,m; cin>>h>>m;

    m-=45;

    if(m<0){
        m+=60;
        h-=1;

        if(h<0) h=23;
    }

    cout<<h<<" "<<m;
}