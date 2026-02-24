#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000001

int T, N;
long long A[MAX];

void solve() {
  for (int i = 1; i <= MAX; i++) {
    for (int j = i; j <= MAX; j += i) {
      A[j] += i;
    }
  }

  for (int i = 1; i <= MAX; i++) {
    A[i] += A[i - 1];
  }

  std::cin >> T;

  while (T--) {
    std::cin >> N;
    std::cout << A[N] << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
