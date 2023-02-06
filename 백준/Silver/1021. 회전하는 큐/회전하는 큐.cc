#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	int n, m, cnt=0; 
	cin >> n >> m;

	//1~n까지 원소 넣어주기 
	for (int i = 1; i <= n; i++) dq.push_back(i);

	while (m--) {
		int x; cin >> x;
		int idx;
		//내 위치에 해당하는 index를 찾기
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == x) {
				idx = i; //deque에서는 인덱스로 접근이 가능함 
				break;
			}
		}

		//'내위치 < size-내위치' 라면 왼쪽으로 옮기는 2번 연산을 실행함 
		if (idx < dq.size() - idx) {
			while (1) {
				if (dq.front() == x) { //삭제할 원소가 맨 앞으로 온 상황 
					dq.pop_front(); //맨앞 원소 삭제 
					break;
				}
				//아직 삭제할 원소가 맨 앞으로 오지 않은 경우이므로
				dq.push_back(dq.front()); //맨 앞 원소를 맨 뒤로 넣음
				dq.pop_front(); //현재 맨 앞 원소를 삭제해줌 
				cnt++;
			}
		}
		//'내위치 > size-내위치' 라면 오른쪽으로 옮기는 3번 연산을 실행함 
		else { 
			while (1) {
				if (dq.front() == x) {
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}