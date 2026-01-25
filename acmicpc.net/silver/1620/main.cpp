#include <cctype>
#include <iostream>
#include <string>
#include <sys/types.h>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <unordered_map>
#include <vector>

void solve() {
  int n, m;

  std::cin >> n >> m;
  std::unordered_map<std::string, int> nameToId;
  std::vector<std::string> idToName(n);
  nameToId.reserve(n);

  std::string x;

  for (int i = 0; i < n; i++) {
    std::cin >> x;
    nameToId.insert({x, i});
    idToName[i] = x;
  }

  for (int i = 0; i < m; i++) {
    std::cin >> x;
    if (std::isdigit(x[0])) {
      int number = std::stoi(x);
      std::cout << idToName[number - 1] << '\n';
    } else {
      auto it = nameToId.find(x);
      if (it != nameToId.end()) {
        std::cout << it->second + 1 << '\n';
      }
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
