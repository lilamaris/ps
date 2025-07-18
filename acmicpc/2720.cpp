#include <iostream>

using namespace std;

void solve() {
  int t, c, n;

  int arr[4] = {1, 5, 10, 25};
  cin >> t;

  while (t--) {
    cin >> c;
    n = 3;
    while (n >= 0) {
      cout << c / arr[n] << " ";
      c %= arr[n--];
    }
  }
}

int main() {
  solve();
  return 0;
}
