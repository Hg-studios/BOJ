#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& v, int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
}

void positive(vector<vector<int>>& v, int n) {
    // 시계방향으로 45도 돌리기
    vector<vector<int>> tmp = v;
    
    // 1. 주 대각선을 가운데 열로 옮김 
    for(int i=1; i<=n; i++) tmp[i][(n+1)/2] = v[i][i];
    
    // 2. 가운데 열을 부 대각선으로 옮김
    for(int i=1; i<=n; i++) tmp[i][n-i+1] = v[i][(n+1)/2];
    // print(tmp,n);

    // 3. 부대각선 열을 가운대 행으로 옮김
    for(int i=1; i<=n; i++) tmp[(n+1)/2][i] = v[n-i+1][i];
    
    // 4. 가운데 행을 주대각선으로 옮김
    for(int i=1; i<=n; i++) tmp[i][i] = v[(n+1)/2][i];
    v = tmp;
    
    return;
}

void negative(vector<vector<int>>& v, int n) {
     // 반시계방향으로 45도 돌리기
    vector<vector<int>> tmp = v;
    
    // 1. 주 대각선을 가운데 행으로 옮김
    for(int i=1; i<=n; i++) tmp[(n+1)/2][i] = v[i][i];
    
    // 2. 가운데 행을 부대각선으로 옮김
    for(int i=1; i<=n; i++) tmp[n-i+1][i] = v[(n+1)/2][i];
    
    // 3. 부대각선을 가운데 열로 옮김
    for(int i=1; i<=n; i++) tmp[i][(n+1)/2] = v[i][n-i+1];
    
    //4. 가운데 열을 주대각선으로 옮김
    for(int i=1; i<=n; i++) tmp[i][i] = v[i][(n+1)/2];
    // print(tmp,n);
    
    v = tmp;
    
    return;
}


int main() {
    int t; cin>>t;
    
    while(t--) {
        int n, d; cin>>n>>d;
        
        vector<vector<int>> v(n+1, vector<int> (n+1,0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cin>>v[i][j];
                // cout<<v[i][j]<<" ";
            }
            // cout<<'\n';
        }
        
        if(d%360!=0) {
            int cnt = abs(d)/45;
            
            if(d>0) {
                for(int i=0; i<cnt; i++) positive(v, n);
            }
            else if(d<0) {
                for(int i=0; i<cnt; i++) negative(v, n);
            }
        }
        
        // break;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout<<v[i][j]<<" ";
            }
            cout<<'\n';
        }
        
    }
    
    return 0;
}