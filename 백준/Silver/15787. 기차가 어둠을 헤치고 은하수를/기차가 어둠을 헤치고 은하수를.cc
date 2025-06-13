#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,m; cin>>n>>m;
    string tmp;
    for(int i=0; i<21; i++) tmp+='0';
    vector<string> v(n+1, tmp);
    
    for(int i=0; i<m; i++) {
        int command; cin>>command;
        
        if(command==1) {
            int x, y; cin>>x>>y;
            v[x][y] = '1';
        }
        else if(command==2) {
            int x, y; cin>>x>>y;
            v[x][y] = '0';
        }
        else if(command==3) {
            int x; cin>>x;
            for(int j=20; j>0; j--) v[x][j] = v[x][j-1];
            v[x][1] = '0';
        }
        else {
            int x; cin>>x;
            for(int j=1; j<20; j++) v[x][j] = v[x][j+1];
            v[x][20] = '0';
        }
    }
    
    map<string, int> mp;
    int cnt=0;
    
    for(int i=1; i<=n; i++) {
        // cout<<v[i]<<" ";
        
        if(mp[v[i]]==0) cnt++;
        mp[v[i]]++;
    }
    
    cout<<cnt;
    return 0;
}