#include <iostream>

using namespace std;

void solve() {
  int n, m, i, j, t;
  cin >> n >> m;
  int arr[n];
  for (int i = 1; i <= n; i++) {
    arr[i - 1] = i;
  }

  while (m--) {
    cin >> i >> j;
    i--, j--;
    for (; i < j;) {
      t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++, j--;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  solve();
  return 0;
}
