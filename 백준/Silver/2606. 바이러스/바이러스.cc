/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<vector<int>> v(n+1);
    
    int m; cin>>m;
    while(m--) {
        int x, y; cin>>x>>y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    vector<bool> visited(n+1);
    queue<int> q;
    
    visited[1] = true;
    q.push(1);
    int count=0; 
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur!=1) count++;
        
        for(int next : v[cur]) {
            if(visited[next]) continue;
            
            visited[next]=true;
            q.push(next);
        }
    }
    
    cout<<count;
    
    return 0;
}