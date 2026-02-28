#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000

int N, A[MAX], dp[MAX];

void solve() {
  std::cin >> N;

  std::fill(dp, dp + MAX, 1);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  int max = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (A[i] > A[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    max = std::max(dp[i], max);
  }

  std::cout << max;
}

int main() {
  IO;
  solve();
  return 0;
}
