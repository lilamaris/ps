#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <algorithm>
#include <set>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::set<std::string> s;
  std::string x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    s.insert(x);
  }

  std::vector<std::pair<int, std::string>> v;
  v.reserve(s.size());
  std::transform(
      s.begin(), s.end(), std::back_inserter(v),
      [](const std::string &s) { return std::make_pair(s.length(), s); });

  std::sort(v.begin(), v.end());

  for (const auto &p : v) {
    std::cout << p.second << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
