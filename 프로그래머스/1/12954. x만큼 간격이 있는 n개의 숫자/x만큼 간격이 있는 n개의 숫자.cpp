#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int cur=0;
    for(int i=0; i<n; i++) {
        cur+=x;
        answer.push_back(cur);
    }
    
    return answer;
}