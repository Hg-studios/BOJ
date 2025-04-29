#include <iostream>
#include <deque>
using namespace std;

struct Balloon {
    int order;
    int value;
};

int main()
{
    deque<Balloon> d;
    
    int n; cin>>n;
    for(int i=1; i<=n; i++) {
        int m; cin>>m;
        // Balloon b = {i, m};{i, m}
        d.push_back({i, m});
    }
    
    while(!d.empty()) {
        Balloon b = d.front();
        d.pop_front();
        cout<<b.order<<" ";
        
        if(b.value>0) { // 양수가 써있는 경우 
            for(int i=0; i<b.value-1; i++) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else { // 음수가 써있는 경우 
            for(int i=0; i<abs(b.value); i++) {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }
    
    return 0;
}