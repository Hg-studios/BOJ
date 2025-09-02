#include <iostream>
using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    
    int l = 1;
    int r = m;
    int ans=0;
    
    int j; cin>>j;
    for(int i=0; i<j; i++) {
        int x; cin>>x;
        
        // 바구니 안에 담기면 움직이지 않음
        if(l<=x && x<=r) continue;
        // cout<<i<<'\n';
        // 바구니 안에 안담겼으면 움직여야 함
        
        // 1. 바구니를 오른쪽으로 옮겨야 되는 경우
        if(r<x) {
            int tmp = x-r;
            ans += tmp;
            r += tmp;
            l += tmp;
        }
        else if(x<l) {
            int tmp = l-x;
            ans += tmp;
            r -= tmp;
            l -= tmp;
        }
        // cout<<x<<"&"<<'\n';
        // cout<<"*"<<l<<" "<<r<<'\n';
    }
    
    cout<<ans;
    
    return 0;
}