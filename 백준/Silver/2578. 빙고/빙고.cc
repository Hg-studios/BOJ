#include <iostream>
using namespace std;

int arr[26][26];
bool visited[26][26];

int dx[] = {1,1};
int dy[] = {1,-1};

void eraseNum(int x) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(x==arr[i][j]) visited[i][j]=true;
        }
    }
}

int bingo() {
    int cnt=0;
    // 가로줄 확인
    for(int i=0; i<5; i++) {
        bool flag=true;
        for(int j=0; j<5; j++) {
            if(!visited[i][j]) {
                flag=false;
                break;
            }
        }
        if(flag) cnt++;
    }
    // 세로줄 확인
    for(int j=0; j<5; j++) {
        bool flag=true;
        for(int i=0; i<5; i++) {
            if(!visited[i][j]) {
                flag=false;
                break;
            }
        }
        if(flag) cnt++;
    }
    
    // 아래로 내려가는 대각선 확인
    int x=0, y=0;
    bool flag=true;
    for(int i=0; i<5; i++) {
        if(!visited[x][y]) {
            flag=false;
            break;
        }
        x = x+dx[0];
        y = y+dy[0];
    }
    if(flag) cnt++;
    
    // 위로 올라가는 대각선 확인
    x=0, y=4;
    flag = true;
    for(int i=0; i<5; i++) {
        if(!visited[x][y]) {
            flag = false;
            break;
        }
        x = x+dx[1];
        y = y+dy[1];
    }
    if(flag) cnt++;
    
    return cnt;
}

int main()
{
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin>>arr[i][j];
        }
    }
    
    int cnt=0;
    for(int i=1; i<=25; i++) {
        int x; cin>>x;
        
        // 수 지우기
        eraseNum(x);
        
        // for(int a=0; a<5; a++) {
        //     for(int b=0; b<5; b++) cout<<visited[a][b]<<" ";
        //     cout<<'\n';
        // }
        // cout<<'\n';
        
        if(i>=5) {
            if(bingo()>=3) {
                cout<<i;
                break;
            }
        }
    }
    
    return 0;
}