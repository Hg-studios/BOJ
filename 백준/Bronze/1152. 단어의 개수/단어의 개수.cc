#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt=0;
    while(1){
        string str; cin>>str;
        if(str=="") break;
        cnt++;
    }
    cout<<cnt;
}