#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size()%2==0) { // 짝수
        int mid = s.size()/2;
        answer += s[mid-1];
        answer += s[mid];
    }
    else { // 홀수
        answer += s[s.size()/2];
    }
    
    return answer;
}