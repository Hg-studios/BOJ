#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    string str; cin>>str;
        
    vector<int> v(26,0);
    
    for(int i=0; i<str.size(); i++) {
        v[str[i]-'A']++;
        
        if(v[str[i]-'A']==3) {
            // 맨 끝의 글자가 아니라면 틀린 것임
            if(i==str.size()-1) {
                cout<<"FAKE"<<'\n';
                return;
            }
            
            // 현재 기준으로 다음 글자를 봄 
            // 같은 글자여야 함 
            if(str[i]!=str[i+1]) {
                cout<<"FAKE"<<'\n';
                return;
            }
            
            // 그 다음에 나오는 3번째로 나올 때마다 추가된 것이므로 건너뜀
            // 추가로 넣은 알파벳은 세는 것에 있어서 카운트하면 안됨 (문제에반데 ㅋㅋ.. 이걸 어케알아)
            i++; // 그래서 건너뜀
            v[str[i]-'A']=0; // 그리고 다시 0으로 초기화
        }
    }
    cout<<"OK"<<'\n';
    return;
}

int main()
{
    int n; cin>>n;
    
    while(n--) {
        solve();
    }
    
    return 0;
}