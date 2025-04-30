#include <iostream>
#include <queue>
using namespace std;

struct Element {
    int origin;
    int ab;
};

struct cmp {
    bool operator() (const Element& e1, const Element& e2) {
        if(e1.ab==e2.ab) return e1.origin>e2.origin;
        return e1.ab>e2.ab;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    priority_queue<Element, vector<Element>, cmp> pq;
    
    while(n--) {
        int x; cin>>x;
        
        if(x==0) {
            //배열이 비어있는 경우 0을 출력
            if(pq.empty()) cout<<"0\n";
            //가장 작은 값을 모두 뺌
            else {
                cout<<pq.top().origin<<'\n';
                pq.pop();
            }
        }
        else {
            pq.push({x, abs(x)});
        }
    }
    
    
    return 0;
}