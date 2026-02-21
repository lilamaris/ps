#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1025

int N, M, arr[MAX][MAX];

void solve() {
  std::cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> arr[i][j];
      arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
    }
  }

  int i1, j1, i2, j2, res;
  for (int i = 0; i < M; i++) {
    std::cin >> i1 >> j1 >> i2 >> j2;
    res = arr[i2][j2];
    res -= arr[i2][j1 - 1];
    res -= arr[i1 - 1][j2];
    res += arr[i1 - 1][j1 - 1];

    std::cout << res << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
