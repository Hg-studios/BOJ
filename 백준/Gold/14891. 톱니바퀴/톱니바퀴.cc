#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string board[4];

//num번째 톱니바퀴를 dir방향으로 회전시키는 함수
//num은 0~3중 하나이며, dir은 1(시계)혹은-1(반시계)임
void rot(int num, int dir) {
    int dirs[4]={};
    dirs[num]=dir;

    //왼쪽으로 회전을 전파
    int idx=num;
    while(idx>0 && board[idx][6]!=board[idx-1][2]){
        dirs[idx-1] = -dirs[idx];
        idx--;
    }

    //오른쪽으로 회전을 전파
    idx=num;
    while(idx<3 && board[idx][2]!=board[idx+1][6]){
        dirs[idx+1] = -dirs[idx];
        idx++;
    }

    //회전을 해야될 바퀴를 회전시킴
    //STL에 rotate함수를 사용하여 회전시킴
    for(int i=0; i<4; i++){
        if(dirs[i]==1){ //시계방향으로 회전
            rotate(board[i].begin(), board[i].begin()+7, board[i].end());
        }
        else if(dirs[i]==-1){ //반시계방향으로 회전
            rotate(board[i].begin(), board[i].begin()+1, board[i].end());
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> board[i];
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        rot(a - 1, b);
    }

    int ans=0;
    for(int i=0; i<4; i++){
        if(board[i][0]=='1') ans+=(1<<i);
    }
    cout<<ans;    
}