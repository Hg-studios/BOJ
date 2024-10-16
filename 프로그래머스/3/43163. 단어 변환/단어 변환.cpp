#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define X first
#define Y second

bool visited[52];

bool checkOneDiff(string a, string b) {
    int diff=0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]!=b[i]) diff++;
    }
    
    if(diff==1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    
    //begin에서 words들 중 1개만 다른 단어가 있으면 queue에 넣기
    queue<pair<string,int>> q; //{단어, 단계 수}
    
    q.push({begin,0});
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.X==target) {
            return cur.Y;
        }
        
        for(int i=0; i<words.size(); i++) {
            if(visited[i]) continue; //방문한적이있으면 탐색x
            
            if(checkOneDiff(cur.X, words[i])) {
                visited[i] = true;
                q.push({words[i],cur.Y+1});
            }
        }
    }
    
    return 0;
}