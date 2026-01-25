#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_set>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::unordered_set<std::string> words;
  words.reserve(n);

  std::string x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    words.insert(x);
  }

  int count = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> x;
    count += words.count(x) ? 1 : 0;
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
