#include <algorithm>
#include <iostream>
#include <vector>

#define IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

bool search(std::vector<int> &v, int val) {
  int l = 0, r = v.size() - 1, m;
  while (l <= r) {
    m = l + ((r - l) / 2);
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
  int n, val;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  std::sort(v.begin(), v.end());
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> val;
    std::cout << search(v, val) << " ";
  }
}

int main() {
  IO;
  solve();
  return 0;
}
