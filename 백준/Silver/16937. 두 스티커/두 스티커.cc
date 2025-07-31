#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h,w; cin>>h>>w;
    
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int> (2));
    
    for(int i=0; i<n; i++) {
        cin>>v[i][0]>>v[i][1];
        // cout<<v[i][0]<<" "<<v[i][1]<<" ";
    }
    
    int mx=-1;
    
    // 1. 2개 뽑기
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            // cout<<i<<" "<<j<<'\n';
            // 2. 2개 뽑은 거에서 그대로, 90도를 돌리는 것 총 4가지 경우
            for(int k=0; k<4; k++) {
                int r1, c1, r2, c2;
                
                if(k==0) { // 2개 다 그대로
                    r1 = v[i][0];
                    c1 = v[i][1];
                    r2 = v[j][0];
                    c2 = v[j][1];
                }
                else if(k==1) {
                    r1 = v[i][1];
                    c1 = v[i][0];
                    r2 = v[j][0];
                    c2 = v[j][1];
                }
                else if(k==2) {
                    r1 = v[i][0];
                    c1 = v[i][1];
                    r2 = v[j][1];
                    c2 = v[j][0];
                }
                else {
                    r1 = v[i][1];
                    c1 = v[i][0];
                    r2 = v[j][1];
                    c2 = v[j][0];
                }
                
                int tmp = r1*c1 + r2*c2;
                
                if(r1<=h && r2<=h && c1+c2<=w) mx = max(mx, tmp);
                if(c1<=w && c2<=w && r1+r2<=h) mx = max(mx, tmp);
            }
        }
    }
    
    cout<<(mx==-1 ? 0 : mx);
    
    return 0;
}