#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<bool> v(31, false);
    for(int i=0; i<28; i++) {
        int x; cin>>x;
        v[x] = true;
    }
    
    for(int i=1; i<=30; i++) {
        if(!v[i]) cout<<i<<'\n';
    }
    
    return 0;
}