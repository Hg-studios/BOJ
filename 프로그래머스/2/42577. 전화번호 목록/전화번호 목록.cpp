#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> m;
    
    // 1190, 11 이 순서대로 나온다면 내 코드에서는 잡아내지 못함.
    // 그래서 phone_book을 길이가 짧은 순서대로 정렬해야되는데 -> 이걸 어케 하란말임?
    // 그래서 생각한 게 어차피 같은 거끼리는 정렬하면 알아서 길이순으로 될 것이기 때문에 그냥 정렬만 해줌
    sort(phone_book.begin(), phone_book.end());
    
    for(string phone : phone_book) {
        string tmp="";
        for(int i=0; i<phone.size(); i++) {
            tmp += phone[i];
            
            if(m[tmp]!=0) return false;
        }
        m[phone]++;
    }
    
    return true;
}