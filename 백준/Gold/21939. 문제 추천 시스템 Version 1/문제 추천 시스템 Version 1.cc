#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct problem {
    int num;
    int level;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    set<pair<int,int>> s;
    map<int, int> m;
    
    int n; cin>>n;
    while(n--) {
        int p, l; cin>>p>>l;
        s.insert({l,p});
        m[p]=l;
    }
    
    int mm; cin>>mm;
    while(mm--) {
        string op; cin>>op;
        
        if(op=="recommend") {
            int x; cin>>x;
            
            if(x==1) {
                cout<<(*s.rbegin()).second<<'\n';
            }
            else {
                cout<<(*s.begin()).second<<'\n';
            }
        }
        else if(op=="add") {
            int p,l; cin>>p>>l;
            
            s.insert({l,p});
        }
        else {
            int p; cin>>p;
            s.erase({m[p], p});
        }
    }
    
    
    
    return 0;
}