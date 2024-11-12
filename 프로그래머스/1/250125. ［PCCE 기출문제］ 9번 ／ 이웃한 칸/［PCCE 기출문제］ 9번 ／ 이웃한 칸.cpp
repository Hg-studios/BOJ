#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    int dh[] = {0, 1, -1, 0};
    int dw[] = {1, 0, 0, -1};
    
    for(int i=0; i<4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        
        if(nh<0||nw<0||nh>=n||nw>=m) continue;
        if(board[h][w]==board[nh][nw]) answer++;
    }
    
    return answer;
}