#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

//Q : 근데 왜 덱이지? 
//A : 일단 원소를 삭제하고 해야하므로 배열보단 덱, 큐가 더 적합함
//    그런데 큐가 아니라 덱인 이유는 R이 나올 때마다 정말로 deque를
//	  뒤집는 것이 아니라 R이면 reverse 해야한다는 표시만 해두고 
//	  reverse 되어있다면 pop_back을 해주고, 안되어있다면 pop_front를 하면 됨 
//	  즉, 매번 진짜로 뒤집는 것이 아니라 개념적으로만 뒤집고 앞 혹은 뒤를 삭제해야하므로

void parse(string& tmp, deque<int>& d) {
	int cur = 0;

	for (int i = 1; i + 1 < tmp.size(); i++) {
		if (tmp[i] == ',') {
			d.push_back(cur);
			cur = 0; //cur 초기화
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	//마지막 원소는 if문에 걸리지 않으니 여기서 처리해줌
	//if문 처리를 꼭 해줘야 하는데 그 이유는 cur이 0일 때는 값이 없는 
	//상황인데 그걸 원소 0으로 넣어버리면 덱이 비지 않고 채워지게 됨 
	if(cur!=0) d.push_back(cur);
}

void print(deque<int>& d) {
	cout << "[";
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		//마지막 원소가 아니라면 , 를 출력해줌 
		if (i + 1 != d.size()) cout << ","; 
	}
	cout << "]\n";
}

int main() {
	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		deque<int> d;
		string query; cin >> query;
		int n; cin >> n;
		string tmp; cin >> tmp;
		bool rev = 0, error = 0;

		parse(tmp, d);

		for (char c : query) {
			if (c == 'R') { //R일 때
				if (rev) rev = 0;
				else rev = 1;
			}
			else { //D일 떄
				if (d.empty()) {
					error = 1;
					break;
				}
				if (rev) d.pop_back();
				else d.pop_front();
			}
		}

		if (error) cout << "error\n";
		else { //rev라면 reverse함수로 뒤집은 채로 print함수로 넘겨줌
			if (rev) reverse(d.begin(), d.end());
			print(d);
		}
	}
	return 0;
}