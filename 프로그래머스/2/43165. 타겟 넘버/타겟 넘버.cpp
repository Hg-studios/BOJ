#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int answer=0;
unordered_map<int, int> m;

void recur(int depth, int sum, vector<int>& numbers, int target) {
    if(depth==numbers.size()) {
        if(sum==target) answer++;
        return;
    }
    
    recur(depth+1, sum+numbers[depth], numbers, target);
    recur(depth+1, sum-numbers[depth], numbers, target);
}

int solution(vector<int> numbers, int target) {
    recur(0,0,numbers,target);
    
    return answer;
}