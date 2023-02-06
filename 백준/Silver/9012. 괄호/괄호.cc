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
	
	while (n--) {
		bool error = 0;
		stack<char> s;
		string str; cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else{
				if (s.empty() || s.top()!='(') {
					error = 1;
					break;
				}
				s.pop();
			}
		}
		if (error) cout << "NO\n";
		else if	(!s.empty()) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}