#include <iomanip>
#include <iostream>

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::cout << std::fixed << std::setprecision(9) << a / (double)b << std::endl;
}

int main() {
  solve();
  return 0;
}
