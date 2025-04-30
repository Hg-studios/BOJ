#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    priority_queue<int> pq;
    
    while(n--) {
        int x; cin>>x;
        
        if(!x) { // 0일 때
            if(!pq.empty()) {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else cout<<"0\n";
        }
        
        else {
            pq.push(x);
        }
    }
    
    return 0;
}