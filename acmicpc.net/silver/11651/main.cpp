#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <algorithm>
#include <vector>

struct Pos {
  int x, y;
};

bool comp(const Pos &p1, const Pos &p2) {
  if (p1.y == p2.y)
    return p1.x < p2.x;
  return p1.y < p2.y;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<Pos> v(n);

  for (int i = 0; i < n; i++) {
    std::cin >> v[i].x >> v[i].y;
  }

  std::sort(v.begin(), v.end(), comp);

  for (int i = 0; i < n; i++) {
    std::cout << v[i].x << " " << v[i].y << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
