#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 250000

int A[MAX], N, X;

void solve() {
  std::cin >> N >> X;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];

    if (i != 0) {
      A[i] += A[i - 1];
    }
  }

  int sum, max = 0, cnt = 0;
  for (int r = X - 1, l; r < N; r++) {
    l = r - X + 1;
    if (l != 0) {
      sum = A[r] - A[l - 1];
    } else {
      sum = A[r];
    }
    if (max < sum) {
      max = sum;
      cnt = 1;
    } else if (max == sum) {
      cnt++;
    }
  }

  if (max == 0) {
    std::cout << "SAD";
  } else {
    std::cout << max << '\n' << cnt;
  }
}

int main() {
  IO;
  solve();
  return 0;
}
