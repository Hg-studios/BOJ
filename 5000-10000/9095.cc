#include <iostream>
using namespace std;

int d[1001] = { 0 };

//d[n]은 n을 1,2,3의 합으로 나타내는 방법의 수
int go(int n){
  //일단 1이면 방법이 하나밖에 없으니깐 1
  if(n==1) return 1;
  if(n==2) return 2;
  if(n==3) return 4;
  //이미 그 값이 저장돼 있는 경우 그 값을 씀
  if(d[n]>0) return d[n];
  
  //d[n]값은 go(n-1)+2*go(n-2)임
  d[n] = go(n-1)+go(n-2)+go(n-3);

  return d[n];
}

int main(){
  int m;
  cin >> m;

  while(m--){
    int n;
    cin >> n;
    cout << go(n) << '\n';
  }
  
  
  return 0;
}