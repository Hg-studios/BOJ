#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

bool isValid(int x){
    for(int i=0; i<v.size(); i++){
        if(v[i]==x) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<10; i++){
        int x; cin>>x;
        x %= 42;

        if(isValid(x)) v.push_back(x);
    }

    cout<<v.size();
}