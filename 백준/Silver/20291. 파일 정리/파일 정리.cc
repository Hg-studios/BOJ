#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    map<string, int> m;
    
    while(n--) {
        string s; cin>>s;
        
        // . 을 기준으로 토크나이징하기
        istringstream input;
        input.str(s);
        
        int cnt=0;
        for(string line; getline(input, line, '.'); ) {
            if(cnt%2==1) {
                // cout<<line<< " ";
                m[line]++;
            }
            
            cnt++;
        }
    }
    
    for(auto it = m.begin(); it!=m.end(); ++it) {
        cout<<it->first<<" "<<it->second<<'\n';
    }
    
    return 0;
}