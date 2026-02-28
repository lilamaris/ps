#include <cstddef>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#define MAX 10000

int K, N, A[MAX], MAXLEN;

int getSplitCount(int v, int *arr, std::size_t n) {
  int sum = 0;
  if (v <= 0)
    v = 1;
  for (int i = 0; i < n; i++) {
    sum += arr[i] / v;
  }
  return sum;
}

void solve() {
  long l = 0, r = MAXLEN, m, sp, max = 0;
  while (l <= r) {
    m = l + (r - l) / 2;
    sp = getSplitCount(m, A, K);

    if (sp >= N) {
      l = m + 1;
      if (max < m)
        max = m;
    } else {
      r = m - 1;
    }
  }

  std::cout << max << '\n';
}

void initial() {
  std::cin >> K >> N;

  for (int i = 0; i < K; i++) {
    std::cin >> A[i];
    if (MAXLEN < A[i])
      MAXLEN = A[i];
  }
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
