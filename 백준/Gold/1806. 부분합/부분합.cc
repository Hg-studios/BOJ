#include <iostream>
#include <algorithm>
using namespace std;

int n,s;
int arr[100005];
int mn=0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>arr[i];

    int en=0;
    int tot=arr[0];

    for(int st=0; st<n; st++){
        //현재 st에 대해 합이 s보다 작아지는 en을 아직
        //찾지 못한 상황이므로 찾을 때까지 en을 오른쪽으로 이동함
        while(en<n && tot<s){
            en++;
            if(en!=n) tot+=arr[en];
        }
        if(en==n) break;
        //tot이 s보다 큰 상황이 되면 st을 오른쪽으로 한칸 옮겨줌
        mn=min(mn, en-st+1);
        tot-=arr[st];
    }

    if(mn==0x7fffffff) mn=0;
    cout<<mn;
}