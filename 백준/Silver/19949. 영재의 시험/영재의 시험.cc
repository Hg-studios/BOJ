#include <vector>
#include <iostream>
using namespace std;

int res=0;
vector<int> choose(11);
vector<int> ans(11);

void recur(int idx, int prev, int cnt, int sum) {
    if(idx==10) {
        if(sum>=5) res++;
        
        return;
    }
    
    for(int i=1; i<=5; i++) { // 보기 1번부터 5번까지 고를 수 있음
        int nextSum = sum + (ans[idx]==i);
        
        if(prev==i) {
            if(cnt+1<3) {
                choose[idx]=i;
                recur(idx+1, prev, cnt+1, nextSum);
            }
        }
        else {
            choose[idx]=i;
            recur(idx+1, i, 1, nextSum);
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<10; i++) {
        cin>>ans[i];
        // cout<<ans[i]<<" ";
    }
    
    // 3개 연속 안되게
    recur(0, -1, 0, 0);
    
    cout<<res;
    
    return 0;
}
