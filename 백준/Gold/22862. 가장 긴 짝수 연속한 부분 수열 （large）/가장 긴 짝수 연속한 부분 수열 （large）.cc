#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin>>n>>k;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    // end는 요소를 추가하는 것
    // start는 요소를 빼는 것
    int start=0;
    int mx=-1;
    int cnt=0; //홀수 개수 카운트
    for(int end=0; end<n; end++) {
        if(v[end]%2==1) cnt++;
        
        // 홀수가 k번보다 많으면 
        // 개수를 줄이면서 홀수 개수가 k 이하가 되도록
        // start를 키워야함
        while(cnt>k) {
            if(v[start]%2==1) cnt--;
            start++;
        }
        
        mx = max(mx, end-start+1-cnt); //end-start+1 에다가 cnt도 함께 지워지므로 cnt개수도 빼줘야함
    }
    
    cout<<mx;
    
    
    return 0;
}