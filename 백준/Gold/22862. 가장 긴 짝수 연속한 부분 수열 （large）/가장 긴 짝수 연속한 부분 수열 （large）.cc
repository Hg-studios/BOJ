#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin>>v[i];
    
    // 투포인터로 연속한 부분 수열 중 가장 긴 길이 찾기
    int en=0, ans=-1;
    int cnt = (v[0]%2); // cnt는 st~en까지 홀수 개수
    for(int st=0; st<n; st++) {
        // 해당 st에 대해서 en이 범위를 넘지 않으면서 
        // k개의 홀수를 넘지 않으면 계속해서 en 한칸씩 늘림
        while(en<n-1 && cnt+(v[en+1]%2)<=k) {
            en++;
            cnt+=v[en]%2;
        }
        
        if(cnt<=k) ans = max(ans, en-st+1-cnt);
        
        if(v[st]%2) cnt-=1;
    }
    
    cout<<ans;
    
    return 0;
}