#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    
    // 인풋받기
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>arr[i][j];
        }
    }
    // 누적합 구하기
    for(int i=1; i<=n; i++) {
        for(int j=2; j<=n; j++) {
            arr[i][j] += arr[i][j-1];
        }
    }
    
    for(int i=0; i<m; i++) {
        int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
        
        // 행을 x1~x2을 보면 되고, 열은 누적합이 되어있으니 y2까지 보고 y1-1값을 빼주면 됨
        int result=0;
        for(int a=x1; a<=x2; a++) {
            
            result += arr[a][y2];
            if(y1-1>=1) {
                result -= arr[a][y1-1];
            }
        }
        cout<<result<<'\n';
    }
    
    return 0;
}