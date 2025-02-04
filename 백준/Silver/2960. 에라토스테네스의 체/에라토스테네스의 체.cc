#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, k; cin>>n>>k;
    vector<int> v(n+1);
    
    for(int i=2; i<=n; i++) v[i]=i;
    
    int cnt=0;
    for(int i=2; i<=n; i++) { // 지우려는 수
        for(int j=i; j<=n; j+=i) { // i의 배수를 삭제할 것임
            if(!v[j]) continue;// 이미 지워졌다면 건너뜀  
            
            cnt++;
            v[j]=0;
            
            if(cnt>=k) {
                cout<<j;
                return 0;
            }
        }
    }
    return 0;
}