#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

//1. 길이가 짧은 것부터
//2. 길이가 같으면 사전 순으로
bool cmp(const string& a, const string& b){
     int lena = a.size();
     int lenb = b.size();

     if(lena!=lenb) return lena < lenb;

     return a < b;
}

//s가 v 안에 있는지 확인하는 함수 
//같은 단어가 있으면 1, 없다면 0을 반환
bool check(const string& s){
    for(int i=0; i<v.size(); i++){
        if(v[i]==s) return 1;
    }

    return 0;
}

int main(){
    int n; cin>>n;

    string str;
    while(n--){
        cin>>str;

        //이전에 나온적이 있는 단어인지를 확인함
        if(!check(str)) v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v) cout<<i<<'\n';
    
    return 0;
}