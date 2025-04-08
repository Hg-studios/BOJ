#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 99999999
// #define INF -1
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    
    while(m--) {
        int a,b,t; cin>>a>>b>>t;
        
        d[a][b]=t;
    }
    
    for(int i=1; i<=n; i++) d[i][i]=0;
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    int k; cin>>k;
    vector<int> friends(k);
    
    for(int i=0; i<k; i++) cin>>friends[i];
    
    int min_dis=INF;
    vector<int> ans;
    
    // i는 모이고자 하는 도시에 해당됨
    for(int i=1; i<=n; i++) {
        // 해당 도시를 선택했을 때 친구들의 왕복시간 중 최대를 찾아야 함
        int max_dis=-1;
        
        for(int j=0; j<friends.size(); j++) {
            int dis=0;
            
            // 해당 친구의 왕복시간
            dis += d[friends[j]][i];
            dis += d[i][friends[j]];
            
            if(max_dis<dis) max_dis = dis;
        }
        
        if(min_dis>max_dis) {
            ans.clear();
            ans.push_back(i);
            min_dis=max_dis;
        }
        else if(min_dis==max_dis) {
            ans.push_back(i);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    
    return 0;
}