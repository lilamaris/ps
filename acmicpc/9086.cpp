#include <iostream>

using namespace std;

void solve() {
  int t;
  string str;
  cin >> t;
  while (t--) {
    cin >> str;
    cout << str[0] << str[str.length() - 1] << endl;
  }
}

int main() {
  solve();
  return 0;
}
