#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int x : arr) answer+=x;
    answer = answer/arr.size();
    
    return answer;
}