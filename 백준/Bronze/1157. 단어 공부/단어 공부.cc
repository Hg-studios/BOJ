#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int alpha[26];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str; cin>>str;
    
    for(int i=0; i<str.size(); i++){
        if(str[i]<'a') alpha[str[i]-'A']++;
        else alpha[str[i]-'a']++;
    }

    int mxIdx=0;
    bool flag=0;
    for(int i=1; i<26; i++){
        if(alpha[i]>alpha[mxIdx]) {
            mxIdx=i;
            flag=0;
        }
        else if(alpha[i]==alpha[mxIdx]) flag=1;
    }

    char x = 'A';

    if(flag) cout<<"?";
    else cout<<(char)(x+mxIdx);

    return 0;
}