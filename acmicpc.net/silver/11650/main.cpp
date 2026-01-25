#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#include <algorithm>
#include <vector>

class Pos {
public:
  int x, y;
  Pos(int x, int y);
  void show() { std::cout << x << " " << y << '\n'; };
};
Pos::Pos(int x, int y) : x(x), y(y) {}

bool comp(Pos p1, Pos p2) {
  if (p1.x == p2.x)
    return p1.y < p2.y;
  return p1.x < p2.x;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<Pos> v;

  int x, y;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> y;
    v.push_back(Pos(x, y));
  }

  std::sort(v.begin(), v.end(), comp);

  for (int i = 0; i < n; i++) {
    v[i].show();
  }
}

int main() {
  IO;
  solve();
  return 0;
}
