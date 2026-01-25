#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define SIZE 10001

void solve() {
  int n, arr[SIZE] = {0};

  std::cin >> n;

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    arr[x]++;
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < arr[i]; j++) {
      std::cout << i << '\n';
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
