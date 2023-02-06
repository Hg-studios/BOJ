#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int cnt = 0;

	while (n--) {
		stack<char> s;
		string str; cin >> str;

		for (int i = 0; i < str.size(); i++) {
			//스택이 비었거나 짝이 없는 경우
			if (s.empty() || s.top() != str[i]) s.push(str[i]);
			//짝이 있는 경우
			else if (s.top() == str[i]) {
				s.pop();
			}
		}
		if (s.empty()) cnt++;
	}
	cout << cnt;

	return 0;
}