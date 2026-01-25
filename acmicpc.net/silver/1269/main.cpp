#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_set>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::unordered_set<int> a;
  std::unordered_set<int> b;
  a.reserve(n);
  b.reserve(m);

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    a.insert(x);
  }

  for (int i = 0; i < m; i++) {
    std::cin >> x;
    b.insert(x);
  }

  int sum = 0;
  for (const auto &it : a) {
    if (b.count(it) == 0)
      sum++;
  }

  for (const auto &it : b) {
    if (a.count(it) == 0)
      sum++;
  }

  std::cout << sum;
}

int main() {
  IO;
  solve();
  return 0;
}
