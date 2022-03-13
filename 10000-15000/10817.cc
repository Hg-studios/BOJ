#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int a,b,c=0;

  vector<int> v;

  cin >> a;
  cin >> b;
  cin >> c;

  v.push_back(a);
  v.push_back(b);
  v.push_back(c);

  sort(v.begin(), v.end());

  v.pop_back();

  cout<<v.back();

} 