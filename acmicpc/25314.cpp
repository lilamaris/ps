#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  for (int i = n; i > 0; i -= 4)
    std::cout << "long ";
  std::cout << "int" << std::endl;
}

int main() {
  solve();
  return 0;
}
