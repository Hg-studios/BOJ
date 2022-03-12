#include <iostream>
#include <algorithm>
using namespace std;

//nCm = n!/(n-m)!m!

int main(){
  long long two =0, five =0;
  long long n, m;
  cin >> n >> m;

  //nCm에서 2의 개수 구하기
  for(long long i=2; i<=n; i*=2){
    two += n/i;
  }
  for(long long i=2; i<=n-m; i*=2){
    two -= (n-m)/i;
  }
  for(long long i=2; i<=m; i*=2){
    two -= m/i;
  }

  //nCm에서 5의 개수 구하기
  for(long long i=5; i<=n; i*=5){
    five += n/i;
  }
  for(long long i=5; i<=n-m; i*=5){
    five -= (n-m)/i;
  }
  for(long long i=5; i<=m; i*=5){
    five -= m/i;
  }
  
  cout << min(two, five) << '\n';
  
  return 0;
}