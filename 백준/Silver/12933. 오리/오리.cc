#include <iostream>
#include <vector>
using namespace std;

char quack[] = {'q', 'u', 'a', 'c', 'k'};

int main()
{
    string s; cin>>s;
    vector<bool> visited(s.size(), false);
    
    if(s.size()%5!=0) {
        cout<<-1;
        return 0;
    }
    
    int cnt=0, ans=0;
    
    while(1) {
        // 한 바퀴 쭉 돌면서 quack 순서대로 나오는지 확인하기 
            
        int tmpCnt = 0; // 총 몇 개의 알파벳이 통과됐는지
        int qIdx = 0; // quack 중 어떤 알파벳을 찾아야 되는지
        
        for(int i=0; i<s.size(); i++) {
            if(visited[i]) continue; // 방문했으면 넘어감 
            if(s[i]!=quack[qIdx]) continue; // 찾아야하는 알파벳이 아니면 넘어감
            
            
            qIdx = (qIdx+1)%5; // 그 다음 알파벳 찾으러
            visited[i]=true;
            tmpCnt++;
        }
        
        // 한 바퀴 쭉 돌았을 때 
        // quack이 5개씩 돌아서 다시 0 인덱스로 와야 함
        // tmpCnt이 5의 배수가 아니라면 quack이 나오지 않은 것이므로
        // zzzaa 처럼 q가 나오지 않으면 계속 tmpCnt는 0임 
        // qzzzz 라면? qIdx가 0이 아니기 때문에 그것 때문에 조건에 걸리게 됨
        // 즉, tmpCnt가 0이면 아예 quack 중 일치하는 알파벳이 하나도 나오지 않은 것이고,
        // tmpCnt가 0이 아닌데 qIdx가 0이 아니면 5개 알파벳이 나오지 못한 것임!
        if(qIdx!=0 || tmpCnt==0) {
            cout<<-1;
            return 0;
        }
        
        cnt+=tmpCnt;
        ans++;
        if(cnt==s.size()) break;
    }
    
    cout<<ans;
    
    return 0;
}