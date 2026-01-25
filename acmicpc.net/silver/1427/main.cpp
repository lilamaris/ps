#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <algorithm>
#include <vector>

bool desc(int n1, int n2) { return n1 > n2; }

void solve() {
  std::string n;
  std::cin >> n;

  std::vector<int> v;
  for (int i = 0; i < n.length(); i++) {
    v.push_back(n[i] - '0');
  }

  std::sort(v.begin(), v.end(), desc);

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i];
  }
}

int main() {
  IO;
  solve();
  return 0;
}
