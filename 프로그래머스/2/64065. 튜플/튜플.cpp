#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

bool cmp (pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    
    for(int i=2; i<s.size(); i++) {
        if(isdigit(s[i])) {
            int num=0;
            
            // 2자리 이상을 처리해야 함
            while(isdigit(s[i])) {
                num *= 10;
                num += (s[i]-'0');
                i++;
            }
            
            m[num]++;
        }
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++) {
        answer.push_back(v[i].first);
    }
    
    
    return answer;
}