#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;  cin>>n;
    
    // 원래는 n^3이지만 두 개의 합(sum)을 구해서 
    // -sum이 있는지 확인해보면 n^2logn 이므로 4초 안에 가능함
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
    
    ll ans=0;
    
    // 하나를 고정해두고
    // 나머지 두개는 투포인터로 정하기
    for(int i=0; i<n-2; i++) {
        int target = -v[i];
        int start=i+1, end=n-1;
        
        while(start<end) {
            int sum = v[start] + v[end];
            
            // 답에 해당하는 두 수를 구한 경우 
            if(sum == target) {
                int vstart=v[start], vend=v[end];
                
                // 두 수가 같다면 이 수의 개수만큼의 조합 개수를 구해야 함 
                if(vstart==vend) {
                    ans += (end-start+1) * (end-start) / 2;
                    break; // 답을 찾았으니
                }
                // 두 수가 다르다면 각각의 수의 개수를 구해서 그 개수의 곱을 구해야 함
                else {
                    int dstart=0, dend=0;
                    
                    // 왼쪽 수의 개수
                    while(v[start]==vstart) {
                        dstart+=1;
                        start++;
                    }
                    // 오른쪽 수의 개수
                    while(v[end]==vend) {
                        dend+=1;
                        end--;
                    }
                    
                    ans+=dstart*dend;
                }
            }
            // 아직 두 수를 못 구한 경우 
            else {
                if(sum>target) end--;
                else start++;
            }
        }
    }
    
    cout<<ans;
    
    return 0;
}