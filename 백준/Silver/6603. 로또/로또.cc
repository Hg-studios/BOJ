#include <iostream>
#include <algorithm>
using namespace std;

int arr[15]; //k개 뽑힌 수들 중에서 6개만 뽑을 것임 
bool visited[15]; //방문 여부 체크 

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int k; cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		
		//앞에 6개만 뽑히는 것이므로 값을 0으로 해줌 
		int choice[15];
		for (int i = 0; i < 15; i++) choice[i] = 1;
		for (int i = 0; i < 6; i++) choice[i] = 0;

		//while문 안에 인자가 arr가 아니라 choice라는 것을 주의하자!
		do {
			for (int i = 0; i < k; i++) {
				if (choice[i] == 0) cout << arr[i] << " ";
			}
			cout << '\n';
		} while (next_permutation(choice, choice + k));

		cout << '\n';
	}
	
	return 0;
}