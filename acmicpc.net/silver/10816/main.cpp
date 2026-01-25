#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_map>

void solve() {
  int n, m;

  std::cin >> n;

  std::unordered_map<int, int> counts;

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    auto it = counts.find(x);
    if (it != counts.end()) {
      it->second++;
    } else {
      counts.insert({x, 1});
    }
  }

  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> x;
    auto it = counts.find(x);
    if (it != counts.end()) {
      std::cout << it->second << ' ';
    } else {
      std::cout << 0 << ' ';
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
