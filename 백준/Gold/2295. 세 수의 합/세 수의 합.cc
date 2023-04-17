#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1005];
vector<int> two;
//시간복잡도를 낮추기 위해서 새로운 아이디어가 필요함
//두 값을 묶어서 벡터v에 저장함
//이중포문을 돌면서 a[i]-a[j]가 v에 있는지 이분탐색으로 찾음
//이 때, i은 n-1~0이며 j는 0부터 i까지임

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            two.push_back(a[i]+a[j]);
        }
    }
    sort(two.begin(), two.end());

    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(binary_search(two.begin(),two.end(),a[i]-a[j])){
                cout<<a[i];
                return 0;
            }
        }
    }
}