#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000000

int M, N;
int A[MAX];

void solve() {
  int l = 1, h = A[N - 1], m, x, result = 0;

  while (l <= h) {
    m = l + (h - l) / 2;
    x = 0;
    for (int i = 0; i < N; i++) {
      x += A[i] / m;
    }

    if (M <= x) {
      result = m;
      l = m + 1;
    } else {
      h = m - 1;
    }
  }

  std::cout << result;
}

void initial() {
  std::cin >> M >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::sort(A, A + N);
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
