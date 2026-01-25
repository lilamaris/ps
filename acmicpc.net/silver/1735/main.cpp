#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }

int lcm(int a, int b) { return a * b / gcd(a, b); }
void solve() {
  int a1, b1, a2, b2, n, m, i;

  std::cin >> a1 >> b1 >> a2 >> b2;
  n = (a1 * b2) + (a2 * b1);
  m = b1 * b2;
  i = gcd(n, m);
  std::cout << n / i << ' ' << m / i;
}

int main() {
  IO;
  solve();
  return 0;
}
