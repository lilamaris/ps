#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100001

int N, M, P[MAX];

void solve() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> P[i];

    if (i != 0) {
      P[i] += P[i - 1];
    }
  }

  std::cin >> M;

  int s, e;

  for (int i = 0; i < M; i++) {
    std::cin >> s >> e;

    if (0 == s - 1) {
      std::cout << P[e - 1] << '\n';
    } else {
      std::cout << P[e - 1] - P[s - 2] << '\n';
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
