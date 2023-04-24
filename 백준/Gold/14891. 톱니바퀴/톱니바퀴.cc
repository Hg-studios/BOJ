#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

string board[4];
vector<int> v[4];
int k;

//num번째 톱니바퀴를 dir방향으로 회전시키는 함수
//num은 0~3중 하나이며, dir은 1(시계)혹은-1(반시계)임
void rot(int num, int dir) {
    //회전시킬 톱니바퀴 검사하기
    bool w[4];
    fill(w, w + 4, 0);
    
    //다른 바퀴가 도는 것과 상관없이 num번째 톱니바퀴는 무조건 회전함
    w[num]=1;

    //첫번째 바퀴를 돌리는 경우
    if (num == 0) {
        //첫번째 두번째 바퀴 검사
        if (v[0][2] + v[1][6] == 1) { //둘중하나가 s,n인 경우
            w[0] = 1;
            w[1] = 1;
            //두번째 세번째 바퀴 검사
            if (v[1][2] + v[2][6] == 1) { //둘중하나가 s,n인 경우
                w[2] = 1;
                //세번째 네번째 바퀴 검사
                if (v[2][2] + v[3][6] == 1) {
                    w[3] = 1;
                }
            }
        }
    }
    //두번째 바퀴를 돌리는 경우
    else if (num == 1) {
        //첫번째 두번째 바퀴 검사
        if (v[0][2] + v[1][6] == 1) {
            w[0] = 1;
            w[1] = 1;
        }
        //두번째 세번째 바퀴 검사
        if (v[1][2] + v[2][6] == 1) {
            w[1] = 1;
            w[2] = 1;
            //세번째 네번째 바퀴 검사
            if (v[2][2] + v[3][6] == 1) {
                w[3] = 1;
            }
        }
    }
    //세번째 바퀴를 돌리는 경우
    else if (num == 2) {
        //세번째 네번째 바퀴 검사
        if (v[2][2] + v[3][6] == 1) {
            w[2] = 1;
            w[3] = 1;
        }
        //두번째 세번째 바퀴 검사
        if (v[1][2] + v[2][6] == 1) {
            w[1] = 1;
            w[2] = 1;
            //첫번째 두번째 바퀴 검사
            if (v[0][2] + v[1][6] == 1) {
                w[0] = 1;
            }
        }
    }
    //네번재 바퀴를 돌리는 경우
    else { //num==3
        //세번째 네번째 바퀴 검사
        if (v[2][2] + v[3][6] == 1) {
            w[2] = 1;
            w[3] = 1;
            //두번째 세번째 바퀴 검사
            if (v[1][2] + v[2][6] == 1) {
                w[1] = 1;
                //첫번째 두번째 바퀴 검사
                if (v[0][2] + v[1][6] == 1) {
                    w[0] = 1;
                }
            }
        }
    }

    //바퀴의 회전 방향을 정해줌 
    int d[4];
    if (num == 0) {
        d[0] = d[2] = dir;
        d[1] = d[3] = -1 / dir;
    }
    else if (num == 1) {
        d[1] = d[3] = dir;
        d[0] = d[2] = -1 / dir;
    }
    else if (num == 2) {
        d[2] = d[0] = dir;
        d[1] = d[3] = -1 / dir;
    }
    else { //num==3
        d[1] = d[3] = dir;
        d[0] = d[2] = -1 / dir;
    }

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < v[i].size(); j++) {
    //             cout << v[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    //w1~w4 중 회전가능한 바퀴를 회전시켜줌
    //시계방향 회전 - 맨뒤에 있는 원소를 빼서 맨앞으로 넣어줌
    //반시계방향 회전 - 맨앞에 있는 원소를 빼서 맨뒤에 넣어줌

    for (int i = 0; i < 4; i++) {
        if (w[i] == 1) { //회전시켜야하는 바퀴인 경우
            if (d[i] == 1) { //시계방향으로 회전
                int x = v[i].back();
                v[i].erase(v[i].end()-1);
                v[i].insert(v[i].begin(), x);
            }
            else { //반시계방향으로 회전
                int x = v[i].front();
                v[i].erase(v[i].begin());
                v[i].push_back(x);
            }
        }
    }

// cout<<"K: "<<k<<'\n';
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < v[i].size(); j++) {
//             cout << v[i][j];
//         }
//         cout << '\n';
//     }
//     cout << '\n';

}

int score() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (v[i][0] == 1) {
            if (i == 0) sum += 1;
            else if (i == 1) sum += 2;
            else if (i == 2) sum += 4;
            else if (i == 3) sum += 8;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> board[i];
        for (int j = 0; j < 8; j++) {
            v[i].push_back(board[i][j] - '0');
        }
    }

    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        rot(a - 1, b);
    }

    cout << score();
}