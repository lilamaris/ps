#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)

bool s(const std::vector<int> &v, int val) {
  int l = 0, r = v.size() - 1, m;

  while (l <= r) {
    m = (l + r) / 2;
    if (v[m] == val)
      return true;
    else if (v[m] < val)
      l = m + 1;
    else
      r = m - 1;
  }

  return false;
}

void solve() {
  int n, m, e;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
    std::cin >> v[i];
  std::cin >> n;
  std::sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    std::cin >> m;
    std::cout << s(v, m) << "\n";
  }
}

int main() {
  IO;
  solve();
  return 0;
}
