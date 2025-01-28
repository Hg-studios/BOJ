#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    if(v.size()==1) cout<<"1";
    else {
        bool incre = true; // true로 초기화 
        int cnt = 2; // 지금까지 연속해서 커지거나 작아지는 수열의 길이 저장, 0하고 1 인덱스는 볼 거니깐 2로 초기화 
        int scnt = 0; // 같은 수 개수 세는 변수
        
        if(v[1]-v[0]>0) {
            incre = true;
        }
        else if(v[1]-v[0]<0) {
            incre = false;
        }
        else if(v[1]-v[0]==0) {
            scnt=2;
        }
        
        int ans=-1;
        for(int i=2; i<n; i++) {
            // 수가 커지는 경우
            if(v[i]-v[i-1]>0) {
                if(incre) { //원래 증가 중이었으면 
                    cnt++; // cnt 하나 증가 
                    scnt=0; // 연속해서 같은 수인 경우가 아니게 되었으므로
                }
                else { // 원래 감소하고 있었으면
                    incre = true;
                    if(scnt!=0) cnt=scnt+1;
                    else cnt=2;
                    scnt=0;
                }
            }
            // 수가 작아지는 경우
            else if(v[i]-v[i-1]<0) {
                if(incre) { //원래 증가 중이었으면
                    incre = false;
                    if(scnt!=0) cnt = scnt+1;
                    else cnt=2;
                    scnt=0;
                }
                else { // 원래 감소 중이었으면
                    cnt++;
                    scnt=0;
                }
            }
            // 수가 같은 경우 
            else {
                if(scnt!=0) scnt++;
                else scnt=2;
                cnt++;
            }
            // cout<<"#"<<v[i]<<" ";
            // cout<<cnt<<'\n';
            ans = max(ans, cnt);
        }
        // cout<<'\n';
        cout<<ans;
    }
    
    
    return 0;
}