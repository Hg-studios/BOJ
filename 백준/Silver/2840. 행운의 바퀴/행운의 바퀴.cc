#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
vector<bool> check(26);
int main()
{
    int n,k; cin>>n>>k;
    v.resize(n,' ');
    
    
    int idx=0;
    while(k--) {
        int s; char c;
        cin>>s>>c;
        
        idx=(idx+s)%n;
        
        if(v[idx]==c) continue;
        
        // 다른 자리에 이미 나온 알파벳은 나오면 안됨
        if(check[c-'A']) { // 오류
            cout<<"!";
            return 0;
        }
        check[c-'A'] = true;
        
        if(v[idx]!=' ') { // 오류
            cout<<"!";
            return 0;
        }
        v[idx]=c;
    }
    
    // idx부터 거꾸로 출력하기
    for(int i=0; i<n; i++) {
        v[idx]==' ' ? cout<<"?" : cout<<v[idx];
        idx = (idx-1+n)%n;
    }
    
    return 0;
}