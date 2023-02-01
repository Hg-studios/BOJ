#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  cin >> m;
  
  queue<int> q;
  
  for(int i=0; i<n; i++){
    q.push(i+1);  
  }

  cout << "<";

  for(int i=0; i<n-1; i++){
    for(int j=0; j<m-1; j++){
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << ">" << '\n';
  
  return 0;
}