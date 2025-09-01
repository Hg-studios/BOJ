#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int turn = 0; // 몇번째 단어인지
    
    map<string, int> m;
//     while(1) {
//         // 등장했던 단어라면
//         if(m[words[turn]]!=0) {
//             answer.push_back(turn%n+1); // 현재 말하고 있는 사람
//             answer.push_back(turn/n+1); // 몇 번째 차례인지
            
//             return answer;
//         }
        
//         // 아직 등장하지 않은 단어라면
//         m[words[turn]]++;
        
//         turn++;
//     }

    for(int i=0; i<words.size(); i++) {
        string cur = words[i];
        
        if(m[cur]!=0) {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            
            return answer;
        }
        
        // 두번째 단어부터는 끝말을 잘 이었는지 확인해야 함
        if(i!=0) {
            string str = words[i-1];
            if(str[str.size()-1] != words[i][0]) {
                answer.push_back(i%n+1);
                answer.push_back(i/n+1);

                return answer;
            }
        }
        
        m[cur]++;
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}