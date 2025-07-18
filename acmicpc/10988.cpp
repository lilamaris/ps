#include <iostream>

using namespace std;

void solve() {
  string str;
  cin >> str;

  int l = 0, r = str.length() - 1;

  while (l < r) {
    if (str[l] != str[r]) {
      cout << "0";
      return;
    }
    l++, r--;
  }
  cout << "1";
}

int main() {
  solve();
  return 0;
}
