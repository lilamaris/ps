#include <cstring>
#include <iostream>

int q[10000], f = 0, b = 0;

void solve() {
  int n, v;

  char c[6];
  std::cin >> n;
  for (; n--;) {
    std::cin >> c;
    if (0 == strncmp("pu", c, 2)) {
      std::cin >> v;
      q[b++] = v;
      continue;
    }
    if (0 == strncmp("po", c, 2)) {
      if (f == b)
        std::cout << -1 << '\n';
      else {
        std::cout << q[f++] << '\n';
      }
      continue;
    }
    if (0 == strncmp("si", c, 2)) {
      std::cout << b - f << '\n';
      continue;
    }
    if (0 == strncmp("em", c, 2)) {
      bool e = f == b;
      std::cout << (e ? 1 : 0) << '\n';
      continue;
    }
    if (0 == strncmp("fr", c, 2)) {
      bool e = f == b;
      std::cout << (e ? -1 : q[f]) << '\n';
      continue;
    }
    if (0 == strncmp("ba", c, 2)) {
      bool e = f == b;
      std::cout << (e ? -1 : q[b - 1]) << '\n';
      continue;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}
