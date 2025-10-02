#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    // 전형적인 위상정렬
    
    // income 배열이 필요함
    // bfs 시작 전에 income 을 채우고, 실제로 이 값이 오면 -- 했던 거 같음 .... 
    // 근데 이러면 B한테 오는 경우가 C가 아니라 A가 와도 count만 하는 거라면 1로 되는디 .....?
    
    map<char, int> m;
    int turn=1;
    for(auto cur : skill) m[cur] = turn++; // map에 skill의 순서를 저장함
    
    for(auto cur : skill_trees) {
        int turn=1;
        bool flag=true;
        for(auto s : cur) {
            if(skill.find(s)!=-1) { // skill 에 포함된 스킬이라면
                if(m[s]!=turn) {
                    flag = false;
                    break;
                }
                else {
                    turn++;
                }
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}