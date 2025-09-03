#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> s;
    int n = elements.size();
    
    for(int i=1; i<=n; i++) { // 개수 
        for(int j=0; j<n; j++) { // 시작점 
            int tmp = 0;
            for(int k=j; k<j+i; k++) { // 시작점에서 개수만큼
                tmp += elements[k%n];
            }
            s.insert(tmp);
        }
    }
    
    answer = s.size();
    
    return answer;
}