#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, k; cin>>n>>k;
    vector<int> v(n+1);
    vector<bool> check(n+1);
    
    int cnt=0;
    while(1) {
        int mn=0;
        // 지워지지 않은 가장 작은 수 찾기
        for(int i=2; i<=n; i++) {
            if(check[i]) continue;
            mn = i;
            break;
        }
        
        // 지워지지 않은 가장 작은 수의 배수를 제거
        for(int i=1; i<=n/mn; i++) {
            // 이미 삭제가 되어있다면 넘어감
            if(check[mn*i]) continue;
            
            // 삭제되지 않았으면 삭제해줌
            cnt++;
            check[mn*i]=true;
            
            // k번째 지우는 수가 되었다면 출력 후 끝냄
            if(cnt>=k) {
                cout<<mn*i;
                return 0;
            }
        }
    }
    return 0;
}