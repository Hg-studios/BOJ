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
    
    // 1이 선택이 되고 2, 3, 4가 차례로 선택이 됨
    // 1->2 선택 후 2에서 또 다시 3, 4 이렇게 선택이 됨
    // 하나가 선택되면 그걸 끝까지 파서 결과를 내고 다시 돌아오게 되는데
    // 마치 스택처럼, 1->2->3->4 순으로 들어갔다면 4->3->2->1 (level)순으로 나오게 됨
    // 그러면 맨 처음에 1->2를 선택했다고 했을 때 이 친구는 1->2->3->4를 돌고
    // 다시 level 3 인 3 대신에 4를 들어가고 이 과정도 끝나면 다시
    // level 2 로 가서 3, 4의 깊이탐색을 시작함
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