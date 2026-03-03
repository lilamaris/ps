#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000000000

int X, Y;

double getZ(int x, int y) { return (y * 100.) / x; }

int solve(int X, int Y) {
  int l = 0, h = MAX, m;
  int z = getZ(X, Y), dz;

  while (l <= h) {
    m = l + (h - l) / 2;
    dz = getZ(m + X, m + Y);

    if (z < dz) {
      h = m - 1;
    } else {
      l = m + 1;
    }
  }
  if (l > MAX) {
    return -1;
  } else {
    return l;
  }
}

void initial() {
  std::cin >> X >> Y;

  std::cout << solve(X, Y);
}

int main() {
  IO;
  initial();
  return 0;
}
