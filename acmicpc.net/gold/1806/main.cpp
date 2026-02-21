#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100001
#define MAXLEN 100000001

int N, S, A[MAX];

void solve() {
  std::cin >> N >> S;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  int l = 0, r = 1, sum = A[0], ml = MAXLEN;

  while (l < r && r <= N) {
    if (sum >= S) {
      ml = std::min(ml, r - l);
      sum -= A[l++];
    } else {
      sum += A[r++];
    }
  }

  std::cout << (ml == MAXLEN ? 0 : ml);
}

int main() {
  IO;
  solve();
  return 0;
}
