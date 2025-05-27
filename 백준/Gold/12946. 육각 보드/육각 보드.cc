#include <iostream>
#include <cstring>
using namespace std;

int n; 
int my[] = {-1, -1, 0, 1, 1, 0}; 
int mx[] = {0, 1, 1, 0, -1, -1}; 
int color[51][51]; // 색칠 여부 (0 또는 1로 이분 그래프 색, -1은 아직 색칠 안된 상태)
int ny, nx, y, x; 
int ans = 0; // 최소 색의 개수 결과값 (1~3 가능)
char arr[51][51]; 

void dfs(int y, int x, int c){
    color[y][x] = c; // 현재 칸에 색 c를 칠함
    ans = max(ans, 1); // 최소 색 하나는 필요하므로 1은 무조건 필요

    for(int i = 0; i < 6; i++){
        ny = y + my[i];
        nx = x + mx[i];
        
        if(arr[ny][nx] == 'X'){ // 인접한 칸이 색칠 대상이라면
            if(color[ny][nx] == -1){ // 아직 색칠되지 않았다면
                dfs(ny, nx, 1 - c); // 다른 색으로 재귀 호출
                ans = max(ans, 2); // 최소 2가지 색이 필요함
            }
            else if(color[ny][nx] == c){ // 이미 색칠되었는데 현재 색과 같다면
                ans = max(ans, 3); // 인접한 셀이 같은 색이면 이분 그래프 불가 -> 3색 필요
                cout << 3 << "\n"; // 바로 정답 출력 후 종료
                exit(0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> n; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    memset(color, -1, sizeof(color));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 색칠 대상이면서 아직 색칠되지 않은 칸이면 DFS 시작
            if(arr[i][j] == 'X' && color[i][j] == -1){
                dfs(i, j, 0); // 색 0부터 시작
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
