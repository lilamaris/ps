#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

void solve() {
  int n, a, b;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> a >> b;
    std::cout << lcm(a, b) << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
