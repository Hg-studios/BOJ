#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> m;
    
    for(int i=0; i<name.size(); i++) m[name[i]] = yearning[i];
    
    for(auto pho : photo) {
        int sum=0;
        for(auto p : pho) {
            sum+=m[p];
        }
        answer.push_back(sum);
    }
    
    return answer;
}