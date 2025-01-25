#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a, p;

int power(int a) {
    int res = 1;
    for(int i=0; i<p; i++) {
        res*=a;
    }
    return res;
}

int dupli(vector<int> &v, int res) {
    // 중복되는 수인지 확인
    for(int i=0; i<v.size(); i++) {
        if(v[i]==res) {
            return i;
        }
    }
    return -1;
}

int main()
{
    cin>>a>>p;
    
    vector<int> v;
    v.push_back(a);
    
    int cur = a;
    while(1) {
        // 수 넣기
        int res=0;
        string s = to_string(cur);
        for(int i=0; i<s.size(); i++) {
            res+=power(s[i]-'0');
        }
        
        // 중복되는 수인지 확인
        int x = dupli(v, res);
        if(x!=-1) {
            cout<<x;
            break; 
        }
        
        // 아직 중복되지 않는다면 수 업데이트
        cur = res;
        v.push_back(res);
    }

    return 0;
}