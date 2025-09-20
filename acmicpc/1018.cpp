#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

void solve() {
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<char>> b(n, std::vector<char>(m, 'X'));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j];
    }
  }

  char rf[] = {'W', 'B'};

  int min = 32;
  for (int i = 0; i < n - 7; i++) {
    for (int j = 0; j < m - 7; j++) {

      for (int r = 0; r < 2; r++) {
        int sum = 0;
        for (int ii = 0; ii < 8; ii++) {
          bool c1 = ii % 2 == 0;
          int ri = ii + i;
          for (int jj = 0; jj < 8; jj++) {
            bool c2 = jj % 2 == 0;
            int rj = jj + j;
            char cr = b[ri][rj];

            if (c1) {
              if (c2 && cr != rf[r])
                sum++;
              if (!c2 && cr == rf[r])
                sum++;
            } else {
              if (c2 && cr == rf[r])
                sum++;
              if (!c2 && cr != rf[r])
                sum++;
            }
          }
        }
        if (sum < min)
          min = sum;
      }
    }
  }

  std::cout << min;
}

int main() {
  IO;
  solve();
  return 0;
}
