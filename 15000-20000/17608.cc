#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> s;
  int num;
  int h;
  int count;
  cin>>num;

  for(int i=0; i<num; i++){
    cin>>h;
    s.push(h);
  }

  int max = s.top();
  s.pop();
  count++;

  while(!s.empty()){
    if(s.top()>max) {
      count++;
      max=s.top();
    } 
    s.pop();
  }

  cout<<count;

  return 0;
} 