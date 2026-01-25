#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_set>

void solve() {
  std::string s;

  std::cin >> s;
  size_t l = s.length();
  std::unordered_set<std::string> unique_str;

  for (size_t i = 0; i < l; i++) {
    for (size_t j = i; j < l; j++) {
      std::string substr = s.substr(i, j - i + 1);
      unique_str.insert(substr);
    }
  }

  std::cout << unique_str.size();
}

int main() {
  IO;
  solve();
  return 0;
}
