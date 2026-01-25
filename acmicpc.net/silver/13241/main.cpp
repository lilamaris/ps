#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

long long int gcd(long long int a, long long int b) {
  return a % b ? gcd(b, a % b) : b;
}

long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}

void solve() {
  long long int a, b;
  std::cin >> a >> b;

  std::cout << lcm(a, b);
}

int main() {
  IO;
  solve();
  return 0;
}
