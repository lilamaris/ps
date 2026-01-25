#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <set>

void solve() {
  int n;
  std::cin >> n;

  std::set<std::string> logs;

  std::string name, status;
  name.reserve(5);
  status.reserve(5);

  for (int i = 0; i < n; i++) {
    std::cin >> name >> status;
    if (status == "enter") {
      logs.insert(name);
    } else {
      logs.erase(name);
    }
  }

  for (auto it = logs.rbegin(); it != logs.rend(); ++it) {
    std::cout << *it << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
