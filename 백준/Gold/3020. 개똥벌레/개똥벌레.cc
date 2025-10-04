#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
#define MAX 100001

int n,h;
vector<int> top, bottom;

void solve() {
    // 누적합 구하기
    // bottom - 큰 수부터 누적하기 
    for(int i=h-1; i>=1; i--) bottom[i] += bottom[i+1];
    
    // top - 작은 수부터 누적하기 
    for(int i=1; i<=h-1; i++) top[i+1] += top[i];
    // for(int i=1; i<=h; i++) cout<<bottom[i]<< " "<<top[i]<<'\n';
    vector<int> ans;
    int minCount = INT_MAX;
    for(int i=1; i<=h; i++) {
        int result = bottom[i] + top[i];
        if(result < minCount) {
            minCount = bottom[i] + top[i];
            ans = vector<int>();
            ans.push_back(i);
        }
        else if(result == minCount) {
            ans.push_back(i);
        }
    }
    
    cout<<minCount<<" "<<ans.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>h;
    
    bottom = vector<int>(h+1, 0);
    top = vector<int>(h+1, 0);
    
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        
        // 누적합을 위해서 그 길이가 나오는 횟수를 count
        if(i%2==0) {
            bottom[x]++;        
        }
        else top[h-x+1]++;
    }
    
    solve();
    
    return 0;
}