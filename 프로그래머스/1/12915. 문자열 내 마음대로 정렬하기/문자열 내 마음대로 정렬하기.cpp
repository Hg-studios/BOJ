#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<pair<char, string>> v; //n번째 문자, 단어
    
    for(string x : strings) {
        v.push_back({x[n], x});
    }
    
    sort(v.begin(), v.end());
    
    for(auto x : v) {
        answer.push_back(x.second);
    }
    
    return answer;
}