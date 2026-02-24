#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 10001

int N, M, A[MAX];

void solve() {
  std::cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
    A[i] += A[i - 1];
  }

  int l = 0, r = 1;

  int cnt = 0;
  while (l <= r && r <= N) {
    int sum = A[r] - A[l];
    if (sum == M)
      cnt++;
    if (sum < M) {
      r++;
    } else {
      l++;
    }
  }

  std::cout << cnt;
}
int main() {
  IO;
  solve();
  return 0;
}
