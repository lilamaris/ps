#include <iostream>

using namespace std;

void solve() {
  int n, m, i, j, k;

  cin >> n >> m;

  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }

  while (m--) {
    cin >> i >> j >> k;
    i--, j--;
    for (int ti = i; ti <= j; ti++)
      arr[ti] = k;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
int main() {
  solve();
  return 0;
}
