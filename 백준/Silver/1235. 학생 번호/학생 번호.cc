#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<string> v(n);
    
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    for(int i=v[0].size()-1; i>=0; i--) { //어느 인덱스까지 볼 것인가
        set<string> s;
        
        
        for(int j=0; j<n; j++) {
            // cout<<v[j].substr(i, v[0].size()-i)<<" ";
            s.insert(v[j].substr(i, v[0].size()-i));
        }
        
        if(s.size()==v.size()) {
            cout<<v[0].size()-i;
            break;
        }
    }
    
    return 0;
}