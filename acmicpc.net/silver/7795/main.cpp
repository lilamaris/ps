#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 20000

int T, N, M;
int A[MAX];

int solve(int target) {
  int l = 0, h = N - 1, m;
  while (l <= h) {
    m = l + (h - l) / 2;

    if (target < A[m]) {
      h = m - 1;
    } else {
      l = m + 1;
    }
  }

  return l;
}

void initial() {
  std::cin >> T;

  while (T--) {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
      std::cin >> A[i];
    }

    std::sort(A, A + N);

    int t, sum = 0;
    for (int i = 0; i < M; i++) {
      std::cin >> t;
      sum += N - solve(t);
    }

    std::cout << sum << '\n';
  }
}

int main() {
  IO;
  initial();
  return 0;
}
