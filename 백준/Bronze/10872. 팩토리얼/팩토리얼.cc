#include <iostream>
using namespace std;

int fac(int n){
  if(n==1) return 1;
  else return n*fac(n-1);
}

int main(){
  int n;
  cin >> n;

  if(n==0) cout<<1;
  else cout << fac(n) << '\n';
  
  return 0;
}