#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n; cin >> n;

	while (n--) {
		int alpha[26] = {};
		string s1, s2; cin >> s1 >> s2;

		for (auto c : s1) alpha[c - 'a']++;
		for (auto c : s2) alpha[c - 'a']--;

		bool isPossible = 1;

		for (int i : alpha) {
			if (i != 0) isPossible = 0;
		}

		if(isPossible) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}