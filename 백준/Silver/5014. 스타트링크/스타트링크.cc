#include <iostream>
#include <queue>
using namespace std;

int dist[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //F층건물, 강호가있는S층, 스타트링크G층, 위로U층, 아래로D층
    int F, S, G, U, D;
    cin>>F>>S>>G>>U>>D;
    fill(dist, dist+1000005, -1); //초기화를 -1로
    
    queue<int> q;
    dist[S]=0;
    q.push(S);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i : {cur+U, cur-D}){
            //건물을 벗어나면 이동할 수 없음
            if(i<1||i>F) continue;
            //이미 방문한 층이면 이동x -> 최소이동이아니므로
            if(dist[i]!=-1) continue;

            dist[i]=dist[cur]+1;
            q.push(i);
        }
    }

    if(dist[G]==-1) cout<<"use the stairs";
    else cout<<dist[G];

    return 0;
}