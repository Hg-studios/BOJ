#include <iostream>
#include <algorithm>
#include <string>]
#include <vector>
using namespace std;

vector<long long> v;

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	string st;
	
	for (int i = 0; i < n; i++) {
		cin >> st;
		reverse(st.begin(), st.end());
		v.push_back(stoll(st));
	}

	sort(v.begin(), v.end());

	for (auto i : v) cout << i << '\n';

	return 0;
}

