#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#include <algorithm>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> v;

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    v.push_back(x);
  }

  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());

  std::cout << v[k - 1];
}

int main() {
  IO;
  solve();
  return 0;
}
