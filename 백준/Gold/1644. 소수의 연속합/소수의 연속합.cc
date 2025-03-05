#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

void eratos() {
    vector<bool> tmp(n+1,true);
    
    for(int i=2; i<=n; i++) {
        if(!tmp[i]) continue; // 이미 i의 배수들은 지워졌다는 것
        for(int j=i+i; j<=n; j+=i) {
            tmp[j] = 0;
        }
    }
    
    for(int i=2; i<=n; i++) {
        if(tmp[i]!=0) arr.push_back(i);
    }
    
    // for(int x : arr) cout<<x<<" ";
}

int main()
{
    cin>>n;
    
    // 에라토스테네스의 체 구하기
    // arr벡터에 소수들이 저장됨
    eratos();
    if(arr.size()==0) {
        cout<<0;
        return 0;
    }
    
    int st=0, en=0, sum=arr[st], ans=0;
    
    // 시작점을 한칸씩 늘림
    for(int st=0; st<arr.size(); st++) {
        // 끝점은 합이 목표값인 n보다 작으면서 범위를 벗어나지 않을 때까지
        // 오른쪽으로 한칸씩 이동
        while(sum<n && en<arr.size()) {
            en++;
            sum+=arr[en];
        }
        
        // sum값이 n보다 커지거나 같아진 것임 
        if(sum==n) ans++;
        
        // for문에 의해서 st가 한칸 옮겨질 것이므로 sum에서 그 값을 빼줌
        sum -= arr[st];
    }
    
    cout<<ans;
    
    return 0;
}