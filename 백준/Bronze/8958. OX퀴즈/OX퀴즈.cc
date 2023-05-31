#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    while(n--){
        string str; cin>>str;

        int cnt=0;
        int ans=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='O') cnt++;
            else cnt=0;

            ans+=cnt;
        }
        cout<<ans<<'\n';
    }

    return 0;
}