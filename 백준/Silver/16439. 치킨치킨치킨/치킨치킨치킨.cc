#include <iostream>
#include <vector>
using namespace std;

int n, m; 
vector<int> pick;
int ans = -1;

void recur(int start, int cur, vector<vector<int>>& v) {
  if(cur==3) {
    // for(int x : pick) cout<<x<<" ";
    // cout<<'\n';
    
    int sum = 0;
    // n명의 사람을 돌면서 
    for(int i=0; i<n; i++) {
      int tmp = -1;
      // 뽑힌 치킨 3종류 중 어떤 것이 가장 큰 만족도인지 확인
      for(int x : pick) {
        if(v[i][x]>tmp) tmp = v[i][x];
      }
      sum += tmp;
    }
    
    if(sum>ans) ans = sum;
    
    return;
  }
  
  for(int i=start; i<m; i++) {
    pick[cur] = i;
    recur(i+1, cur+1, v);
  }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m;
    
    vector<vector<int>> v(n, vector<int> (m,0));
    
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cin>>v[i][j];
        // cout<<v[i][j]<<" ";
      }
    }
    
    // 치킨을 3개만 골라야함 
    // 중복없는 조합
    pick.resize(3,0);
    recur(0,0,v);
    
    cout<<ans;
    
    return 0;
}