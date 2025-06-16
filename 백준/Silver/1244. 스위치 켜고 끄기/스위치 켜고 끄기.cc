#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> v(n+1,0);
    for(int i=1; i<=n; i++) {
        cin>>v[i];
    }
    
    int m; cin>>m;
    while(m--) {
        int a,b; cin>>a>>b;
        
        // 남학생
        if(a==1) {
            for(int i=1; i<=n/b; i++) {
                v[b*i]=1-v[b*i];
            }
        }
        // 여학생
        else {
            // 우선 본인을 바꿈
            v[b]=1-v[b];
            
            for(int i=1; i<=n; i++) {
                if(b+i>n || b-i<=0) break; // 범위 넘어가면 끝
                if(v[b+i]==v[b-i]) {
                    v[b+i]=1-v[b+i];
                    v[b-i]=1-v[b-i];
                }
                else{
                    break;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        cout<<v[i]<<" ";
        if(i%20==0) cout<<'\n';
    }
    
    return 0;
}