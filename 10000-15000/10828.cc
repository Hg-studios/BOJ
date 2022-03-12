#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Stack{
    int data[10000];
    int size;
    
    Stack(){
        size=0;
    }
    
    void push(int num){
        data[size] = num;
        size += 1;
    }
    
    bool empty(){
        if(size==0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int pop(){
        if(empty()) {
            return -1;
        }
        else{
            size -= 1;
            return data[size];
        }
    }
    
    int top(){
        if(empty()) {
            return -1;
        }
        else {
            return data[size-1];
        }
    }
};

int main(){
    int n;
    cin >> n;
    
    Stack s;
    
    while(n--){
        string cmd;
        cin >> cmd;
        
        if(cmd == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop"){
            cout << s.pop() << '\n';
	    //백준은 cout << (s.empty() ? -1 : s.top()) << '\n'; if (!s.empty()) {s.pop(); } 라고 했는데 굳이?
        }
        else if(cmd == "top"){
            cout << s.top() << '\n';
	    //백준은 cout << (s.empty() ? -1 : s.top()) << '\n'; 이렇게 했는데 굳이라는 생각이 듦
        }
        else if(cmd == "size"){
            cout << s.size << '\n';
        }
        else if(cmd == "empty"){
            cout << s.empty() << '\n';
        }
    }
    return 0;
}
