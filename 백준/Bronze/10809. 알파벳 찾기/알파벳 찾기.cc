#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin>>str;

    fill(alpha, alpha+26, -1);
    for(int i=0; i<str.size(); i++){
        if(alpha[str[i]-'a']==-1) {
            alpha[str[i]-'a']= i;
        }
    }

    for(int i=0; i<26; i++){
        cout<<alpha[i]<<" ";
    }
}