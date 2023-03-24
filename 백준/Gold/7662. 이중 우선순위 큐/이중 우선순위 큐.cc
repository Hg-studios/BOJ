#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin>>tc;
    while(tc--){
        multiset<int> ms;
        int k; cin>>k;

        while(k--){
            char c; cin>>c;
            int x; cin>>x;
            if(c=='I'){
                ms.insert(x);
            }
            else{ //c=='D'
                if(ms.empty()) continue; //비어있을 땐 삭제x
                if(x==-1){
                    //ms.erase(*ms.begin())을 하게되면 이와 같은
                    //값을 모두 지워버리게 되어서 주의 요망!
                    //그래서 삭제할 주소 자체를 넘겨버리기 
                    ms.erase(ms.begin());
                }
                else{ //x==1
                    ms.erase(prev(ms.end()));
                }
            }
        }
        if(ms.empty()) cout<<"EMPTY\n";
            else cout<<*prev(ms.end())<<" "<<*ms.begin()<<'\n';
    }

}