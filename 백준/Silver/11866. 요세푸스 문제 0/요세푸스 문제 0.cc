/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    queue<int> q;
    
    for(int i=1; i<=n; i++) q.push(i);
    vector<int> v;
    
    while(!q.empty()) {
        for(int i=0; i<k-1; i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        v.push_back(q.front());
        q.pop();
    }
    
    cout<<"<";
    for(int i=0; i<v.size(); i++) {
        cout<<v[i];
        if(i!=v.size()-1) cout<<", ";
    }
    cout<<">";
    
    return 0;
}