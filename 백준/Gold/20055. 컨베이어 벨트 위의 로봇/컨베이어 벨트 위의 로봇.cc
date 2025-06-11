#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin>>n>>k;
    
    vector<int> d(n*2); // 칸의 내구도
    for(int i=0; i<n*2; i++) {
        cin>>d[i];
    }
    
    // 로봇의 위치를 저장할 공간 -> 삽입 삭제가 쉬워야 함 
    
    // 0 ~ 2n-1칸이 있는 상황
    // 컨베이터벨트 위에 벨트가 돌아가는 상황이고 벨트 위에 로봇을 올리는 것
    
    int turn=0;
    int cntZero=0;
    vector<bool> robots(n, false); // robots의 위치에 true로 로봇을 표시해줌, n개만 만들어도 됨 
    
    while(1) {
        turn++;
        
        // 1. 로봇과 벨트 모두를 한 칸 이동
        // 1-1. 벨트 한 칸씩 이동
        int tmp = d[n*2-1];
        for(int i=n*2-1; i>0; i--) {
            d[i] = d[i-1];
        }
        d[0] = tmp;
        
        // cout<<"[내구도 한 칸 이동]\n";
        // for(int x : d) cout<<x<<" ";
        // cout<<'\n';
        
        // cout<<"[로봇이동 전]\n";
        // for(int x : robots) cout<<x<<" ";
        // cout<<'\n';
        
        // 1-2. 로봇 한 칸 이동
        for(int i=n-1; i>0; i--) {
            robots[i] = robots[i-1];
            robots[i-1] = false;
        }
        
        // cout<<"[로봇이동 후]\n";
        // for(int x : robots) cout<<x<<" ";
        // cout<<'\n';
        
        // 1-3. 이동 후 내리는 위치에 있는 로봇 삭제
        robots[n-1] = false;
        
        // cout<<"[로봇이동 후 마지막 로봇 처리]\n";
        // for(int x : robots) cout<<x<<" ";
        // cout<<'\n';
        
        // 2. 로봇만 이동가능하다면 이동
        // 2-1. 가장 오래된 로봇부터 한 칸씩 옮겨줌줌
        // & 이동했는데 내리는 칸이면 삭제
        // & 이동한 칸의 내구도 1 감소
        for(int i=n-2; i>=0; i--) {
            if(!robots[i]) continue; // 로봇이 없는 칸은 넘어감
            
            // 로봇이 있는 칸
            // 다음 칸으로 옮길 수 있는지 확인 
            if(d[i+1]>0 && !robots[i+1]) {
                robots[i+1] = robots[i]; // 다음 칸에 옮겨주고
                robots[i] = false; // 내 칸의 로봇은 없앰 
                d[i+1]--; // 이동하는 칸의 내구도 1 감소 
            }
        }
        // 2-2. 마지막 칸에 온 로봇은 삭제
        robots[n-1] = false;
        // cout<<"[로봇이동 후3]\n";
        // for(int x : robots) cout<<x<<" ";
        // cout<<'\n';
        
        // 3. 올리는 칸에 로봇 올리기
        
        // 3-1. 올리는 칸 내구도 0이 아닌지 확인 후 올리기
        if(d[0]>0) {
            robots[0] = true;
            // 3-2. 올리는 칸의 내구도 1 감소
            d[0]--;
        }
        
        
        // 4. 내구도가 0인 칸의 개수 구하기
        int cnt=0;
        for(int i=0; i<n*2; i++) {
            if(!d[i]) cnt++;
        }
        if(cnt>=k) break;
        
        // cout<<"[최종] "<<turn<<'\n';
        // for(int x : robots) cout<<x<<" ";
        // cout<<'\n';
        
        // for(int x : d) cout<<x<<" ";
        // cout<<'\n';
        // cout<<'\n';
        
        
        
        
        // if(cnt>=3) break;
        // if(turn>=24) break;
    }
    
    cout<<turn;
    
    return 0;
}