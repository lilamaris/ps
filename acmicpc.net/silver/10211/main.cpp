#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000

int T, N, A[MAX];

void solve() {
  std::cin >> T;

  while (T--) {
    std::cin >> N;

    int res = -987654321;
    for (int i = 0; i < N; i++) {
      std::cin >> A[i];
      if (i != 0) {
        A[i] = std::max(A[i] + A[i - 1], A[i]);
      }
      res = std::max(A[i], res);
    }

    std::cout << res << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
