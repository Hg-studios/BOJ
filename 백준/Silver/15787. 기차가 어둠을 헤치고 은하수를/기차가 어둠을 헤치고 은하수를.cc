/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    
    vector<int> v(n+1, 0);
    
    for(int i=0; i<m; i++) {
        int command; cin>>command;
        
        if(command==1) {
            int x, y; cin>>x>>y;
            // v[x][y] = '1';
            v[x] |= (1<<y);
        }
        else if(command==2) {
            int x, y; cin>>x>>y;
            // v[x][y] = '0';
            v[x] &= ~(1<<y);
        }
        else if(command==3) {
            int x; cin>>x;
            // for(int j=20; j>0; j--) v[x][j] = v[x][j-1];
            // v[x][1] = '0';
            
            v[x] = v[x]<<1;
            v[x] &= ((1<<21)-1);
        }
        else {
            int x; cin>>x;
            // for(int j=1; j<20; j++) v[x][j] = v[x][j+1];
            // v[x][20] = '0';
            v[x] = v[x]>>1;
            v[x] &= ~1; //0번째 위치는 승객이 넘어왔어도 0으로 만들어줘야 함 
            //ex. (20) 01001111 (1)
            
            
        }
    }
    
    vector<bool> vis(1<<21, false);
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(vis[v[i]]==false) cnt++;
        vis[v[i]] = true;
    }
    
    cout<<cnt;
    return 0;
}