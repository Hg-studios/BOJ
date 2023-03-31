#include <iostream>
#include <deque>
using namespace std;
const int MX = 100000+2;

int n,k;
int dist[MX];
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    fill(dist,dist+MX, -1); //-1로 초기화

    dist[n]=0; //n에서 출발
    dq.push_back(n);

    while(!dq.empty()){
        auto cur = dq.front(); dq.pop_front();
        if(cur==k) {
            cout<<dist[cur];
            return 0;
        }

        for(auto i : {cur-1, cur+1, cur*2}){
            if(i<0||i>MX) continue; //범위를 벗어남
            if(dist[i]!=-1) continue; //이미 방문함

            if(i==cur*2){ //*2인 경우는 덱의 앞에 넣음(우선순위 높음)
                dist[i] = dist[cur];
                dq.push_front(i);
            }
            else{
                dist[i] = dist[cur]+1;
                dq.push_back(i);
            } 
        }
    }
    return 0;
}