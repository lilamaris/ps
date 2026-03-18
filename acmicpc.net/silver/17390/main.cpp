#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 300001

int P[MAX];
int N, Q;

void solve() {
  std::cin >> N >> Q;

  P[0] = 0;
  for (int i = 1; i <= N; i++) {
    std::cin >> P[i];
  }

  std::sort(P, P + N + 1);

  for (int i = 2; i <= N; i++) {
    P[i] += P[i - 1];
  }

  int l, r;
  while (Q--) {
    std::cin >> l >> r;

    std::cout << P[r] - P[l - 1] << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
