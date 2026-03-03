#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100000

int N, M;
long long A[MAX];

void solve() {
  long long max = 0;

  long long x;
  for (int i = M - 1; i < N; i++) {
    if (i == M - 1) {
      x = A[i];
    } else {
      x = A[i] - A[i - M];
    }

    max = std::max(max, x);
  }
  std::cout << max;
}

void initial() {
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];

    if (i != 0) {
      A[i] += A[i - 1];
    }
  }
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
