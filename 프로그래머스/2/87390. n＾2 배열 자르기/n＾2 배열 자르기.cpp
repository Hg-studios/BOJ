#include <string>
#include <vector>

using namespace std;
#define ll long long

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(ll i=left; i<=right; i++) {
        int r = i/n;
        int c = i%n;
        
        int tmp = 0;
        if(r<c) tmp = c;
        else tmp = r;
        
        answer.push_back(max(r,c)+1);
    }
    
    
    return answer;
}