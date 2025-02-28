#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// 현재 idx번째 사람을 볼 차례, banned_id에서 cnt번째 사람을 찾는 경우임 

// 중복없는 순열 구하기 ->

// 순열로 구하면 같은 조합의 경우가 서로 다른 경우의 수로 체크될 수가 있을 것 같다...
// 조합으로 구하면,,,, ->

int n, m;
// n : user_id 개수
// m : banned_id 개수
set<int> s;

// 중복없는 순열
void recur(int cnt, int bitmask, vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, vector<string>& arr) {
    if(cnt == m) { //banned_id만큼 뽑혔으면 끝냄
        // cout<<bitmask<<" ";
        // for(auto x : arr) cout<<x<<" ";
        // cout<<'\n';
        
        bool flag = true;
        // 뽑힌 arr을 banned_id 기준에 맞는지 확인
        for(int i=0; i<m; i++) {
            // 각 자리의 단어의 길이 수가 다르면 틀린 것임 
            if(banned_id[i].size() != arr[i].size()) {
                flag = false;
                break;
            }
            // 이제는 단어들의 각 자리를 비교해야 함
            for(int j=0; j<banned_id[i].size(); j++) {
                if(banned_id[i][j]=='*') continue;
                if(banned_id[i][j]!=arr[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        
        // 만약에 모든 조건이 맞다면 set에 넣어줌
        if(flag) s.insert(bitmask);
        
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        
        visited[i]=true;
        arr[cnt] = user_id[i];
        recur(cnt+1, bitmask|(1<<i), user_id, banned_id, visited, arr);
        visited[i]=false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    // solve(0,0);
    
    n = user_id.size();
    m = banned_id.size();
    
    // banned_id 에 대해서 재귀함수로 하나씩 살펴보기
    // 다 맞는 쌍을 구했다면 비트마스킹으로 표시된 문제 표시를 set에 추가함 -> 같은 조합이라면 하나로 쳐야하기 때문
    
    vector<bool> visited(n,false);
    vector<string> arr(m);
    recur(0,0,user_id,banned_id,visited,arr);
    
    answer = s.size();
    cout<<s.size();
    
    return answer;
}