/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// int dx[] = {-1,0,1,0,1,1,-1,-1};
// int dy[] = {0,-1,0,1,1,-1,1,-1};

struct state {
    int start, end;
};

bool cmp (state& a, state& b) {
    if(a.start==b.start) return a.end > b.end;
    return a.start < b.start;
}

bool solve(int i, bool (&check) [1001][366], state& cur) {
    bool wrong = false; // 모든 일정을 넣을 수 있는지 확인
    
    for(int j=cur.start; j<=cur.end; j++) {
        if(check[i][j]) { // 하루라도 넣을 수 없다면 일단 이 줄은 넘어감
            wrong = true;
            continue;
        }
    }
    
    if(!wrong) {
        for(int j=cur.start; j<=cur.end; j++) {
            check[i][j] = true;
            // cout<<i<<" "<<j<<'\n';
        }
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    vector<state> v(n);
    
    int mxC = 0;
    int mxR = 0;
    int mnR = 99999;
    
    for(int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        
        v[i] = {x,y};
        if(y>mxR) mxR=y; 
    }
    
    sort(v.begin(), v.end(), cmp);
    
    mnR = v[0].start;
    
    bool check[1001][366] = {false, }; // 크기가 큰 배열은 동적할당 말고 정적할당이 시간복잡도에 더 효율적 
    
    
    for(auto cur : v) {
        for(int i=1; i<=1000; i++) {
            // i번째 줄에 cur을 넣을 수 있는지 확인 
            if(solve(i, check, cur)) {
                if(i> mxC) mxC = i;
                break;
            }
        }
    }
    
    // 이어져있는지 확인하기
    int maxHeight = 0;
    int maxWidth = 0;
    int h=-1;
    long long ans = 0;
    
    for(int i=mnR; i<=mxR; i++) {
        // 높이만큼 확인하기 
        int highest = -1;
        for(int j=1; j<=mxC; j++) {
            if(check[j][i]) {
                highest = j;
            }
        }
        // 끊긴 경우
        if (highest != -1) {
            maxHeight = max(maxHeight, highest);
            maxWidth += 1;
        } 
        // 연속된 경우 
        else {
            ans += maxHeight * maxWidth;
            maxHeight = 0;
            maxWidth = 0;
        }
        
    }
    
    ans += maxHeight * maxWidth;

    
    // long long ans = 0;
    // bool visited[1001][366] = {false, };
    
    // for(int i=1; i<=1000; i++) {
    //     for(int j=1; j<=365; j++) {
    //         if(visited[i][j]) continue;
    //         if(!check[i][j]) continue;
            
    //         int minX=i, maxX=i, minY=j, maxY=j;
    //         // cout<<"+"<<minX<<" "<<minY<<" "<<" "<<maxX<<maxY<<'\n';
            
    //         queue<pair<int,int>> q;
            
    //         visited[i][j]=true;
    //         q.push({i,j}); //이걸 안넣었음ㅋ..
            
    //         while(!q.empty()) {
    //             auto cur = q.front();
    //             q.pop();
                
    //             int curX = cur.first;
    //             int curY = cur.second;
                
    //             for(int dir=0; dir<8; dir++) {
    //                 int nx = curX + dx[dir];
    //                 int ny = curY + dy[dir];
                    
    //                 if(nx<1||ny<1||nx>1000||ny>365) continue;
    //                 if(visited[nx][ny]) continue;
    //                 if(!check[nx][ny]) continue; // 체크되어있지 않으면 넘어감 
                    
    //                 if(minX>nx) minX = nx;
    //                 if(maxX<nx) maxX = nx;
    //                 if(minY>ny) minY = ny;
    //                 if(maxY<ny) maxY = ny;

    //                 visited[nx][ny] = true;
    //                 q.push({nx,ny});
    //             }
    //         }
            
    //         // cout<<minX<<" "<<maxX<<" "<<minY<<" "<<maxY<<'\n';
    //         ans += (maxX-minX+1) * (maxY-minY+1);
    //         // cout<<"ans : " <<ans<<"\n";
    //     }
    // }
    
    cout<<ans;
    
    return 0;
}