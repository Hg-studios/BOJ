#include <iostream>
#include <algorithm>
using namespace std;

int n;

void bar(const char* str, int k) {
	for (int i = 0; i < k; i++) cout << "____";
	cout << str;
}

void func(int cnt) {
	bar("\"재귀함수가 뭔가요?\"\n", cnt);
	if (cnt == n) bar("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", cnt);
	else {
		bar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", cnt);
		bar("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", cnt);
		bar("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", cnt);
		func(cnt + 1);
	}
	bar("라고 답변하였지.\n", cnt);
}

//void func(int k) {
//	bar(k);
//	cout << "\"재귀함수가 뭔가요 ? \"\n";
//
//	if (k == n) { //base condition
//		
//		bar(k);
//		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
//		bar(k);
//		cout << "라고 답변하였지.\n";
//		return;
//	}
//	
//	bar(k);
//	cout << "\"잘 들어보게.옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
//	bar(k);
//	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
//	bar(k);
//	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
//
//	func(k + 1);
//
//	bar(k);
//	cout << "라고 답변하였지.\n";
//}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	func(0);
	
	return 0;
}