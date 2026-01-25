#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

long int fact(long int i) {
  if (i == 0)
    return 1;
  return i * fact(i - 1);
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << fact(n);
}

int main() {
  IO;
  solve();
  return 0;
}
