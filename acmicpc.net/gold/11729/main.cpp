#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

void print(int from, int to) { std::cout << from << ' ' << to << '\n'; }

void move(int from, int via, int to, int n) {
  if (n == 1) {
    print(from, to);
    return;
  }

  move(from, to, via, n - 1);
  print(from, to);
  move(via, from, to, n - 1);
}

void solve() {
  int n;
  std::cin >> n;

  std::cout << (2 << (n - 1)) - 1 << '\n';
  move(1, 2, 3, n);
}

int main() {
  IO;
  solve();
  return 0;
}
