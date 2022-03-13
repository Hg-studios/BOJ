#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;

  int count=0;
  int temp=0;

  std::cin >> count;

  for(int i=0; i<count;i++){
    q.push(i+1);
  }

  while(count>1){
    cout<< q.front() << " ";
    q.pop();
    temp = q.front();
    q.pop();
    q.push(temp);
    count--;
  }

  std::cout << q.front();
  q.pop();
} 