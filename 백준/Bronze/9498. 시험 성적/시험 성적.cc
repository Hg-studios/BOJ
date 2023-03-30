#include <iostream>
using namespace std;

int main() {
	int s; cin >> s;
	
	if (s >= 90 && s <= 100) cout << "A";
	else if (s >= 80 && s < 90) cout << "B";
	else if (s >= 70 && s < 80) cout << "C";
	else if (s >= 60 && s < 70) cout << "D";
	else cout <<"F";

	return 0;
}