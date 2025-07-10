#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin>>n>>m;
    
    vector<vector<bool>> v(n+1, vector<bool> (n+1, false));
    
    while(m--) {
        int a, b; cin>>a>>b;
        
        v[a][b]=true;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(v[i][k] && v[k][j]) {
                    v[i][j] = true;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(v[i][j]==0 && v[j][i]==0) cnt++;
        }
        cout<<cnt-1<<'\n';
    }
    
    return 0;
}