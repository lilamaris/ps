#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_set>

void solve() {
  int n, m;
  std::cin >> n;

  std::unordered_set<int> cards;
  cards.reserve(n);

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    cards.insert(x);
  }

  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> x;
    std::cout << (cards.count(x) ? 1 : 0) << ' ';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
