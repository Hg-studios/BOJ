#include <string>
#include <vector>
#include <iostream>
using namespace std;

// vector<char> v(5);
char c[] = {'A', 'E', 'I', 'O', 'U'};
int answer;
int cnt;

void recur(int depth, string word, string cur) {
    if(depth==5) {
        return;    
    }
    
    for(int i=0; i<5; i++) {
        cnt++;
        // v[depth]=c[i];
        // cur+=c[i];
        // 현재까지
        // string tmp;
        // for(auto cur : v) {
        //     if(cur!=' ') tmp+=cur;
        // }
        
        // cout<<tmp<<" "<<cnt<<'\n';
        
        // 찾고 있는 단어인 경우
        if(cur+c[i]==word) {
            cout<<"FIND!!!!!!\n";
            answer = cnt;
            return;
        }
        
        recur(depth+1, word, cur+c[i]);
        // cur.erase(cur.end()-1);
    }
}

int solution(string word) {
    recur(0, word, "");
    
    return answer;
}