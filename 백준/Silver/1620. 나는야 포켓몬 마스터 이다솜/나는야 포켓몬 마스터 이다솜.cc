#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    // 이 문제는 아래 세문장이 없으면 시간초과가 된다...
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m; cin>>n>>m;
    
    map<string, int> mp;
    vector<string> v(n+1);
    
    for(int i=1; i<=n; i++) {
        // cout<<i<<" ";
        string s; cin>>s;
        mp[s]=i;
        v[i]=s;
        // cout<<mp[s]<<" ";
    }
    // cout<<mp.find(1).second;
    while(m--) {
        string s; cin>>s;
        
        if(mp[s]!=0) {
            cout<<mp[s]<<'\n';
        }
        else { 
            // 숫자면 전체탐색을 통해 단어를 알아내야 함 
            // 따라서 배열을 하나 더 생성해서 바로 문자열을 알아낼 수 있도록 하자!
            cout<<v[stoi(s)]<<'\n';
        }
    }
    
    return 0;
}