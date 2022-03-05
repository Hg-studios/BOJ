#include <iostream>
using namespace std;

//소수는 2부터 시작이니깐 주어진 수의 루트까지만 검사를 해보면 알 수 있음
// 만약에 15라면 1,3,5,15 인데 루트15이면 약 3.xx라서 반쪽만 검사를 빠르게 하는 것임ㅇㅇ 
bool prime(int n){
  if(n<2) return false;
  for (int i=2; i*i<=n; i++){ //여기에 루트값(실수값)으로 쓰기보다는 정수가 더 좋기 때문에 i*i로 하는 것임.
    if(n%i==0) return false;
  }
  return true;
}

int main(){ 
  //주어진 숫자가 소수인지 아닌지는 이렇게 함 => O(루트n)
  //근데 어떤 범위 안에서 모든 소수를 구하는 문제라면 '에라토스테네스의 체'를 이용함!
  
  int n;
  cin >> n;
  int count =0;

  while(n--){
    int a;
    cin >> a;

    if(prime(a)) count++;
    
  }
  
  cout << count << '\n';
    
  return 0;
}