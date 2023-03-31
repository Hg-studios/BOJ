#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

int n,k;
int dist[100005];
int way[100005];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    fill(dist, dist+100005, -1); //-1로 초기화
    
    way[n]=n; //시작의 의미로 n 저장
    dist[n]=0; //n에서 시작
    q.push(n);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(cur==k) {
            cout<<dist[k]<<'\n';
            break;
        }
        for(auto i : {cur+1, cur-1, cur*2}){
            if(i<0||i>100000) continue;
            if(dist[i]!=-1) continue;

            way[i]=cur;
            dist[i]=dist[cur]+1;
            q.push(i);
        }
    }

    
    //거꾸로 17부터 5까지 가는 경로로 거꾸로 나오게 됨 (k에서 n으로 감)
    //그래서!! deque를 이용하면 매우 편하게 구현가능함
    deque<int> track;
    track.push_back(k);

    while(track.front() != n){
        track.push_front(way[track.front()]);
    }
    for(auto i : track) cout<<i<<" ";

    return 0;
}