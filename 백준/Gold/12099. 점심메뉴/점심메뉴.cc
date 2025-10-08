#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

bool cmp (const pair<int,int>& a, const pair<int,int>& b) {
    return a.Y < b.Y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, q; cin>>n>>q;
    vector<pair<int,int>> product(n);
    vector<int> spicy(n);
    
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        
        product[i] = {a,b};
        spicy[i] = a;
    }
    
    sort(product.begin(), product.end());
    sort(spicy.begin(), spicy.end());
    
    // for(auto x: v) cout<<x.X<<" "<<x.Y<<'\n';
    
    while(q--) {
        int u,v,x,y; cin>>u>>v>>x>>y;
        
        auto start = lower_bound(spicy.begin(), spicy.end(), u) - spicy.begin();
        auto end = upper_bound(spicy.begin(), spicy.end(), v) - spicy.begin();
        
        int cnt=0;
        for(int i=start; i<end; i++) {
            if(x<= product[i].second && product[i].second <=y) cnt++;
        }
        
        cout<<cnt<<'\n';
        
    }
    
    
    return 0;
}