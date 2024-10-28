#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
#define X first
#define Y second

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left=10, right=11; // *는 10, #은 11
    map<int, pair<int,int>> m;
    
    m[1] = {0,0};
    m[2] = {0,1};
    m[3] = {0,2};
    m[4] = {1,0};
    m[5] = {1,1};
    m[6] = {1,2};
    m[7] = {2,0};
    m[8] = {2,1};
    m[9] = {2,2};
    m[0] = {3,1};
    m[10] = {3,0};
    m[11] = {3,2};
    
    for(int number : numbers) {
        if(number==1 || number==4 || number==7) {
            left = number;
            answer += 'L';
        }
        else if(number==3 || number==6 || number==9) {
            right = number;
            answer += 'R';
        }
        else {
            pair<int,int> next = m[number];
            pair<int,int> l = m[left];
            pair<int,int> r = m[right];
            
            int disL = abs(next.X - l.X) + abs(next.Y - l.Y);
            int disR = abs(next.X - r.X) + abs(next.Y - r.Y);
            
            if(disL < disR) {
                left = number;
                answer += 'L';
            }
            else if(disL > disR) {
                right = number;
                answer += 'R';
            }
            else {
                if(hand=="left") {
                    left = number;
                    answer += 'L';
                }
                else {
                    right = number;
                    answer += 'R';
                }
            }
        }
    }
    
    return answer;
}