#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, k;
vector<int> v(12,0);
string pick[5];
string pick2[5];
set<int> s;
bool visited[5];

void recur2(int depth) {
    if(depth==k) {
        string n;
        for(int i=0; i<k; i++) {
            n += pick2[i];
        }
        
        s.insert(stoi(n));
        
        return;
    }
    
    for(int i=0; i<k; i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        pick2[depth] = pick[i];
        recur2(depth+1);
        visited[i] = false;
    }
}

void recur(int idx, int depth) {
    if(depth==k) {
        // 뽑은 k개로 이번에는 순열을 만들어야 함 
        recur2(0);
        
        return;
    }
    
    for(int i=idx; i<n; i++) {
        pick[depth] = to_string(v[i]);
        recur(i+1, depth+1);
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    // n개의 수 중에서 k개를 뽑아야함
    // 중복없는 조합으로 뽑으면 됨
    recur(0,0);
    
    cout<<s.size();
    
    return 0;
}