#include <iostream>
using namespace std;

int d[1000001] = { 0 };

int go(int n){
  //일단 1이면 연산을 안해도 되니까 0을 리턴함
  if(n==1) return 0;
  //이미 그 값이 저장돼 있는 경우 그 값을 씀
  if(d[n]>0) return d[n];
  //d[n]값은 우선 -1 한 연산 횟수에다가 +1한 값임
  d[n] = go(n-1) + 1;
  //2로 나눠진다면 현재 값보다 n/2값까지의 연산 횟수가 작다면 거기에다가 +1
  if(n%2==0){
    int temp = go(n/2)+1;
    if(d[n]>temp) d[n]=temp;
  }
  //3으로 나눠진다면 현재 값보다 n/3값까지의 연산 횟수가 작다면 거기에다가 +1
  if(n%3==0){
    int temp = go(n/3)+1;
    if(d[n]>temp) d[n]=temp;
  }

  return d[n];
}

int main(){
  int n;
  cin >> n;

  cout << go(n) << '\n';
  
  return 0;
}