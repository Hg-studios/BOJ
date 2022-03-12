#include <iostream>
#include <string>
using namespace std;

struct Queue{
  int data[10000];
  int begin;
  int end;

  Queue(){
    begin = 0;
    end = 0 ;
  }

  void push(int x){
    data[end] = x;
    end += 1;
  }

  bool empty(){
    if(begin == end) return true;
    else return false;
  }

  int pop(){
    if(empty()) return -1;
    else {
      begin += 1;
      return data[begin-1];
    }
  }

  int size(){
    return end-begin;
  }

  int front(){
    if(empty()) return -1;
    else return data[begin];
  }

  int back(){
    if(empty()) return -1;
    else return data[end-1];
  }

};
int main(){
  int n;
  cin >> n;

  Queue q;
  
  while(n--){
    string cmd;
    cin >> cmd;

    if(cmd == "push"){
      int x;
      cin >> x;
      q.push(x);
    }
    else if(cmd == "pop"){
      cout << q.pop() << '\n';
    }
    else if(cmd == "size"){
      cout << q.size() << '\n';
    } 
    else if(cmd == "empty"){
      int result = q.empty();
      if(result) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    else if(cmd == "front"){
      cout << q.front() << '\n';
    }
    else if(cmd == "back"){
      cout << q.back() << '\n';
    }
  }
  
  return 0;
}
