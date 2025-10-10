#include <string> 
#include <vector>
#include <map>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> m;
    int turn=0;
    
    for(auto cur : skill) m [cur]=++turn;
    
    for(auto skill_tree : skill_trees) {
        int cnt=0; // skill 안에 있는 문자만 cnt 함
        bool flag=true;
        for(auto cur: skill_tree) {
            if(m[cur]==0) continue; // 선행스킬이 아니면 그냥
            if(m[cur]!=++cnt) { // 만약 선행스킬 순서가 틀리면 다음 단어를 봄
                flag = false;
                break;
            }
        }
    
        if(flag) answer++;
    }
    return answer;
}
