#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

#define X first
#define Y second

int solution(vector<int> topping) {
    int answer = 0;
    
    // 토핑의 전체 개수를 구해놓는다.
    unordered_map<int, int> left, right;
    int kinda=0, kindb=0;
    
    for(auto cur : topping) right[cur]++;
    kindb = right.size();
    
    // 처음에는 B가 다 가지고 있다고 생각하고, 왼쪽에서부터 하나씩 A에게 줌
    
    for(auto cur : topping) {
        // A는 현재 가지고 있지 않은 토핑을 받는 거라서 종류가 하나 증가함
        if(left[cur]==0) kinda++;
        // 한칸씩 옮김 = 모든 토핑이 B거였다가 A에게 하나씩 줌
        left[cur]++;
        
        // B는 가지고 있던 토핑이 0이 되면 종류가 하나 줄어듦 
        right[cur]--;
        if(right[cur]==0) kindb--;
        
        if(kinda == kindb) answer++;
    }
    
    // unordered_map<int, int> l;
    // l[0]++;
    // l[0]--; l[0]--;
    // for(auto x : l) cout<<x.X<<" "<<x.Y;
    
    return answer;
}