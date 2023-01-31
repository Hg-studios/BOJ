#include <iostream>
using namespace std;

int student[13]; //idx 1-6가 여학생, idx7-12이 남학생임 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, room=0; 
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int sex, grade; 
		cin >> sex >> grade;
		student[sex * 6 + grade]++;
	}

	for (int i = 1; i <= 12; i++) {
		room += (student[i] / k);
		if (student[i] % k != 0) room += 1;
	}

	cout << room;

	return 0;
}