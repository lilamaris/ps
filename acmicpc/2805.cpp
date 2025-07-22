#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, m, val;
  std::vector<int> v;

  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> val;
    v.push_back(val);
  }

  std::sort(v.begin(), v.end());

  int l = 0, r = v.size() - 1, mid, sum = 0;

  while (l <= r) {
    sum = 0;
    mid = (r - l) / 2;
    std::cout << l << "<->" << r << " mid: " << mid << std::endl;
    for (int i = mid; i < v.size(); i++) {
      sum += v[i] - v[mid];
    }
    std::cout << sum << std::endl;

    if (sum == m) {
      std::cout << mid << '\n';
      break;
    }

    if (sum > m) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
}

int main() {
  solve();
  return 0;
}
