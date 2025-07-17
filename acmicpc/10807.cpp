#include <iostream>

void solve() {
  int n, v, l;
  std::cin >> n;

  int arr[201];
  std::fill_n(arr, 201, 0);

  while (n--) {
    std::cin >> v;
    arr[v + 100]++;
  }

  std::cin >> l;
  std::cout << arr[l + 100];
}

int main() {
  solve();
  return 0;
}
