#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    // 던전의 개수가 최대 8개이므로, 순열로 모든 순서를 체크해주기
    sort(dungeons.begin(), dungeons.end());
    
    do {
        // 현재 피로도
        int tmp = k;
        int cnt = 0;
        
        for(auto cur : dungeons) {
            // cout<<cur[0]<<" "<<cur[1]<<'\n';
            
            int need = cur[0];
            int use = cur[1];
            
            // 현재 피로도보다 필요한 피로도가 크면 탐색 끝
            if(tmp<need) {
                break;
            }
            
            // 소모 피로도만큼 소모함
            tmp-=use;
            
            if(tmp<0) {
                break;
            }
            
            // 탐험 가능한 던전 개수
            cnt++;
        }
        
        // cout<<cnt<<'\n';
        if(answer<cnt) answer = cnt;
        
        // cout<<'\n';
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}