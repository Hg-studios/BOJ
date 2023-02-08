#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> s;
	string str; cin >> str;

	int sum = 0; //누적해서 더해질 값
	int num = 1; //곱해질 값

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			//스택이 비어있거나 짝이 맞지 않으면 0 출력
			if (s.empty() || s.top()!='(') {
				cout << 0;
				return 0;
			}
			//짝이 정상적으로 맞는 경우이면서 '()' 인 경우
			if (str[i - 1] == '(') {
				sum += num;
			}
			num /= 2;
			s.pop();
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') {
				sum += num;
			}
			num /= 3;
			s.pop();
		}
	}

	if (s.empty()) cout << sum;
	else cout << 0;

	return 0;
}