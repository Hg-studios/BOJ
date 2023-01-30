#include <iostream>
using namespace std;

int young, minsick;

void young_solve(int t) {
	young += 10 + (t / 30) * 10;
}

void min_solve(int t) {
	minsick += 15 + (t / 60) * 15;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	int n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		young_solve(t);
		min_solve(t);
	}
	
	if (young == minsick) cout << "Y M " << young;
	else if(young < minsick) cout << "Y " << young;
	else if(young > minsick) cout << "M " << minsick;

	return 0;
}