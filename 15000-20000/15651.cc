#include <iostream>
using namespace std;

constexpr int N = 9;
int n, m, cnt=0;
int result[N];
bool visited[N];

void dfs(int level){
    if(level==m){
        for(int i=0; i<m; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    //중복을 허용해주려면 visited 여부 체크를 건너뛰면 됨
    for(int i=1; i<=n; i++){
            visited[i] = 1;
            result[level] = i;
            dfs(level+1);
            visited[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    dfs(0);

    return 0;
}