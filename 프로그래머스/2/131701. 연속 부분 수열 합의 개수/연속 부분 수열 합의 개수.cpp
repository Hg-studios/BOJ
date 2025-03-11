#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> s;
    
    // 1부터 elements.size()만큼 
    for(int size=1; size<=elements.size(); size++) {
        // 각 size별로 시작점은 start임
        // 실제 더하기를 시작할 인덱스
        for(int start=0; start<elements.size(); start++) {
            // 시작하는 인덱스부터 size만큼 더하기 
            int sum = 0;
            for(int cnt=start; cnt<start+size; cnt++) {
                sum += elements[cnt%elements.size()];
            }
            s.insert(sum);
        }
    }
    
    answer = s.size();
    
    return answer;
}