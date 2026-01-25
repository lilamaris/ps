#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <algorithm>

void solve() {
  int n = 5, sum = 0;
  int arr[5] = {};

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
    sum += arr[i];
  }

  std::sort(arr, arr + n);

  std::cout << sum / 5 << '\n' << arr[2];
}

int main() {
  IO;
  solve();
  return 0;
}
