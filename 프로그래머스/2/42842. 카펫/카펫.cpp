#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    
    for(int i=1; i*i<=sum; i++) {
        if(sum%i!=0) continue; // 약수가 아닌 경우
        
        if(2*(i+sum/i)-4==brown) {
            answer.push_back(sum/i);
            answer.push_back(i);
            break;
        }
    }
    
    
    return answer;
}