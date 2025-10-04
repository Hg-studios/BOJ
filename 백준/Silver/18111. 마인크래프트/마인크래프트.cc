#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <algorithm>
using namespace std;

#define ll long long 

int n,m,b;
vector<ll> v;

ll solve(ll h) {
    // 높이 i 로 통일하기
    ll inven=b; // 현재 
    ll tmp=0; // 땅을 고르는 데 걸리는 시간 
    
    for(auto cur : v) {
        // 현재 칸의 높이가 목표 높이보다 높은 경우
        // 1번 작업 시작
        if(cur>h) { 
            inven += (cur-h);
            tmp+=2*(cur-h); // 1번 작업은 2초가 걸림
        }
        // 현재 칸의 높이가 목표 높이보다 낮은 경우
        // 2번 작업 시작
        else if(cur<h) { 
            if(inven-(h-cur)<0) return -1; // 현재 가지고 있는 블럭으로는 만들 수 없는 경우
            
            inven -= (h-cur);
            tmp+=1*(h-cur); // 2번 작업은 1초가 걸림
        }
    }
    
    return tmp;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    // 가장 높이가 낮은 층부터 높은 층까지 브루트포스로 하면서 가장 최소 시간 찾기
    
    cin>>n>>m>>b;
    
    // vector<vector<int>> v(n, vector<int> (m));
    v.resize(n*m);
    ll mn = INT_MAX;
    ll mx = INT_MIN;
    
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cin>>v[i][j];
            
    //         if(v[i][j]<mn) mn = v[i][j];
    //         if(v[i][j]>mx) mx = v[i][j];
    //     }
    // }
    
    for(ll i=0; i<n*m; i++) {
        cin>>v[i];
        
        if(v[i]<mn) mn = v[i];
        if(v[i]>mx) mx = v[i];
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    // for(auto cur : v) cout<<cur<<" ";
    
    vector<ll> ans; // 최소 작업 시간이 걸리는 땅의 높이 (여러 개 일 수 있음)
    ll ansH = INT_MAX;
    
    for(ll i=mn; i<=mx; i++) {
        // 높이가 높은 것부터 처리해줘야 됨
        // 왜냐면 인벤토리에 최대한 많은 블록을 채워넣은 뒤에 그 블록 수를 가지고 꺼내서 사용할 수 있는지 확인해야 되므로
        ll result = solve(i);
        
        if(result==-1) continue;
        else {
            if(result<ansH) {
                ansH = result;
                vector<ll> tmp;
                tmp.push_back(i);
                ans = tmp;
            }
            else if(result==ansH) {
                ans.push_back(i);
            }
        }
    }
    
    sort(ans.begin(), ans.end(), greater<int>());
    
    cout<<ansH<<" "<<ans[0];
    
    return 0;
}