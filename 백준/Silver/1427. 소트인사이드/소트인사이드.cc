#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin>>str;

    vector<int> v;
    for(int i=0; i<str.size(); i++){
        int n = str[i]-'0';
        v.push_back(n);
    }

    sort(v.begin(), v.end(), greater<>());

    for(auto i : v) cout<<i;

    return 0;
}