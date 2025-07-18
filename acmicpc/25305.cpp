#include <iostream>

using namespace std;

void solve() {
  int n, k, v, t;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = 0;

  for (int i = 0; i < n; i++) {
    cin >> v;
    arr[i] = v;
  }

  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
  cout << arr[n - k];
}

int main() {
  solve();
  return 0;
}
