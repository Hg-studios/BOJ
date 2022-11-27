#include <iostream>
using namespace std;

constexpr int N = 9;
int n, m; //1부터 n까지 중복없이 m개를 뽑음
int result[N]; //뽑힌 수 저장
bool visited[N]; //방문했는지 체크

void dfs(int cnt){
    if(cnt == m){ //stop condition
        for(int i=0; i<m; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = 1;
            result[cnt] = i; //result 배열에 뽑힌 수열이 순서대로 저장되고 업데이트되기 때문에 초기화는 필요없음
            dfs(cnt+1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0);

    return 0;
}