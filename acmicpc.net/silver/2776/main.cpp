#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000000

int T, N, M;
int A[MAX];

int solve(int x) {
  int l = 0, r = N - 1, m, v;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (x == A[m]) {
      return 1;
    } else if (x > A[m]) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return 0;
}

void initial() {
  std::cin >> T;

  for (int i = 0; i < T; i++) {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
      std::cin >> A[i];
    }

    std::sort(A, A + N);

    std::cin >> M;
    int x;
    for (int i = 0; i < M; i++) {
      std::cin >> x;
      std::cout << solve(x) << '\n';
    }
  }
}

int main() {
  IO;
  initial();
  return 0;
}
