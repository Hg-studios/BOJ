#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack <int> s;
	string res = "";
	int n, cur=1; //cur은 여태까지 넣은 인덱스를 가리킴
	cin >> n;
	
	while (n--) {
		int x; cin >> x;

		if (s.empty() || s.top()<x) { //맨처음에는 엠티임, 엠티일때는 수를 넣어줘야함 
			for (int i = cur; i <= x; i++) {
				s.push(i);
				cur++;
				res += "+";
			}
		}
		//empty가 아니라서 뺄 요소가 있게 되면 top값을 가지고 비교해봐야함
		if (s.top() == x) {
			s.pop();
			res += "-";
		}
		else if (s.top() > x) { 
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}

	return 0;
}