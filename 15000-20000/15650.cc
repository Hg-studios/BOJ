#include <iostream>
using namespace std;

constexpr int N = 9;
int n, m;
int result[N];
bool visited[N];

void dfs(int level, int prev){
    if(level==m){
        for(int i=0; i<m; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=level; i<=n; i++){
        if(prev<i){
            visited[i] = 1;
            result[level] = i;
            dfs(level+1, i);
            visited[i] = 0; 
        }
        
    }
}
int main(){
    cin >> n >> m;
    dfs(0,0);

    return 0;
}