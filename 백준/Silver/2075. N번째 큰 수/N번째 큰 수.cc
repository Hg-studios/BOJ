#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n; cin>>n;
    
    for(int i=0; i<n*n; i++) {
        int x; cin>>x;
        pq.push(x);
        if(pq.size()>n) pq.pop();
    }
    
    cout<<pq.top();
    
    return 0;
}