#include <iostream>
#include <map>
#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr)

int main() {
  IO;

  int n, v;
  std::map<int, int> m;

  std::cin >> n;
  for (; n--;) {
    std::cin >> v;
    m[v]++;
  }

  std::cin >> n;
  for (; n--;) {
    std::cin >> v;
    auto it = m.find(v);
    bool f = it == m.end();
    std::cout << (f ? 0 : it->second) << " ";
  }
}
