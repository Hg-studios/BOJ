#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    map<string, int> m; 
    
    // map은 기본적으로 사전순으로 정렬됨
    
    int total=0;
    while(1) {
        string s;
        //개행을 기준으로 한줄씩 받아야함
        getline(cin, s);
        
        if(s=="") break;
        
        m[s]++;
        total++;
    }
    
    cout<<fixed;
    cout.precision(4);
    
    for(auto& cur : m) {
        
        
        printf("%s %.4f\n", cur.first.c_str(), (cur.second/(double)total)*(double)100);
    }
    
    return 0;
}