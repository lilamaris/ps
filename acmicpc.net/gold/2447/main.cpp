#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

void print(int i, int j, int n) {
  bool isSpace = (i / n) % 3 == 1 && (j / n) % 3 == 1;

  if (isSpace) {
    std::cout << ' ';
  } else {
    if (n / 3 == 0) {
      std::cout << '*';
    } else {
      print(i, j, n / 3);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      print(i, j, n);
    }
    std::cout << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
