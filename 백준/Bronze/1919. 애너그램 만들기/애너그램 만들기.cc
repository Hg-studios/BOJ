#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int alpha1[26] = {}, alpha2[26] = {};
	int sum = 0;
	string s1, s2; cin >> s1 >> s2;

	for (auto c : s1) alpha1[c - 'a']++;
	for (auto c : s2) alpha2[c - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (alpha1[i] >= alpha2[i]) sum += (alpha1[i] - alpha2[i]);
		else sum += (alpha2[i] - alpha1[i]);
	}

	cout << sum;

	return 0;
}