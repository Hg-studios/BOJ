#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,m; cin>>n>>m;
    
    vector<vector<int>> v(n, vector<int> (m,0));
    
    for(int i=0; i<n; i++) {
        string tmp; cin>>tmp;
        for(int j=0; j<m; j++) {
            v[i][j] = tmp[j] - '0';
        }
    }
    
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    // 0이면 오른쪽으로 붙은 것
    // 1이면 아래쪽으로 붙은 것
    
    // 0 1 은 2진수로 모든 경우를 표현할 수 있음
    ll mx = -1;
    
    for(int i=0; i<(1<<(n*m)); i++) {
        ll sum = 0;
        
        // 가로 조각 계산
        for(int r=0; r<n; r++) {
            int tmp = 0;
            for(int c=0; c<m; c++) {
                int idx = r*m + c;
                
                if((i & (1<<idx)) == 0) { // 가로 조각을 찾음 
                    tmp = tmp*10 + v[r][c];
                }
                else { // 가로 조각 끊기면 누적 
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        } 
        
        // 세로 조각 계산
        for(int c=0; c<m; c++) {
            int tmp = 0;
            for(int r=0; r<n; r++) {
                int idx = r*m + c;
                
                if((i&(1<<idx))>0) {
                    tmp = tmp*10 + v[r][c];
                }
                else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        
        if(mx<sum) mx = sum;
    }
    
    cout<<mx;
    
    
    return 0;
}