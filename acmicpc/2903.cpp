#include <iostream>

using namespace std;

void solve() {
  int n, a = 2;
  cin >> n;
  while (n--) {
    a = 2 * a - 1;
  }
  cout << a * a << endl;
}

int main() {
  solve();
  return 0;
}
