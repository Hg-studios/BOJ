#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n; 
    while(n--){
        int x; 
        string str;
        cin>>x>>str;

        for(int i=0; i<str.size(); i++){
            for(int j=0; j<x; j++){
                cout<<str[i];
            }
        }
        cout<<'\n';
    }
    return 0;
}