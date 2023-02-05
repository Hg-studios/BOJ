#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<pair<int, int>> s; //height와 index를 저장함

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int h; cin >> h;

		while (!s.empty()) { //스택이 비어있지 않으면 top과 h를 비교함 
			if (s.top().first > h) { //현재 높이보다 큰 값이 있으면 출력하고 반복문 빠져나감
				cout << s.top().second << " ";
				break;
			}
			s.pop(); //현재 높이보다 크지 않다면 스택에서 제거함 
		}
		
		if (s.empty()) cout << "0 "; //스택이 비어있으면 0을 출력함
		s.push({ h,i }); //스택에 현재 값을 push함
	}
	return 0;
}