#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
int fibo(int n) {
    // if(n<=1) return n;
    if(v[n]!=-1) return v[n];
    
    return v[n] = (fibo(n-1)%1234567 + fibo(n-2)%1234567) %1234567;
}

int solution(int n) {
    v.resize(n+1, -1);
    v[0]=0; v[1]=1;
    
    return fibo(n)%1234567;
}