
#include <string>
 
using namespace std;
 
string solution(int n) {
    string answer = "";
    string arr[3] = {"4", "1", "2"};
    while(n != 0) {
        answer = arr[n % 3] + answer;
        if (n % 3 == 0)
            n = n / 3 - 1;
        else
            n = n / 3;
    }
    return answer;
}
