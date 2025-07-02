#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1e6+1);

int find(int x) {
    if(p[x]==x) return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u==v) return;
    
    p[v] = u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin>>t;
    
    for(int tc=1; tc<=t; tc++) {
        cout<<"Scenario "<<tc<<":"<<'\n';
        
        int n; cin>>n; // 유저의 수
        for(int i=1; i<=n; i++) p[i]=i; // 매 tc마다 초기화 
        
        int k; cin>>k;
        for(int i=0; i<k; i++) {
            int a, b; cin>>a>>b;
            
            uni(a, b);
        }
        
        int m; cin>>m;
        for(int i=0; i<m; i++) {
            int u, v; cin>>u>>v;
            
            if(find(u)==find(v)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}