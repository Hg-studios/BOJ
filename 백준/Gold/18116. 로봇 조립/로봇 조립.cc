#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> p(1e6+1,0); // 초기화를 자기 자신으로 해도 되고, -1로 해도 됨 
vector<int> sz(1e6+1, 1); // 본인이 속해있으므로 일단 사이즈는 1로 초기화 

int find(int x) {
    if(p[x]==x) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a==b) return;
    
    p[b]=a;
    sz[a]+=sz[b];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // 초기화
    for(int i=1; i<=1e6; i++) p[i]=i;
    
    int n; cin>>n;
    
    while(n--) {
        char c; cin>>c;
        
        if(c=='I') {
            int a, b; cin>>a>>b;
            uni(a, b);
        }
        else if(c=='Q') {
            int c; cin>>c;
            
            int p = find(c);
            cout<<sz[p]<<'\n';
        }
    }
    
    return 0;
}