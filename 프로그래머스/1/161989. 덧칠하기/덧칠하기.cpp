#include <string>
#include <vector>
#include <iostream>
using namespace std;

int check(vector<bool>& v, int n) {
    for(int i=1; i<=n; i++) {
        if(!v[i]) return i;
    }
    return -1;
}

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<bool> v(n+1, 1);
    for(int idx : section) v[idx]=0;
    
    while(1) {
        int result = check(v, n);
        
        // -1 이라면 더이상 칠할 곳이 없는 것임
        if(result==-1) break;
        // 아직 칠할 곳이 남은 경우
        else {
            answer++;
            
            // result idx부터 m만큼 칠해줌
            for(int i=result; i<result+m; i++) {
                if(i>n) break; // 칠하다가 범위를 벗어나면 빠져나옴
                if(!v[i]) v[i]=true; // 페인트 칠해줌
            }
        }
    }
    
    return answer;
}