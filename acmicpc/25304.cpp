#include <iostream>

void solve() {
  int x, n, a, b;
  std::cin >> x >> n;

  while (n--) {
    std::cin >> a >> b;
    x -= a * b;
  }

  if (x == 0)
    std::cout << "Yes";
  else
    std::cout << "No";
}

int main() {
  solve();
  return 0;
}
