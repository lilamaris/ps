#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001

int N, M;
long long MOD[MAX];

void solve() {
  std::cin >> N >> M;

  long long sum = 0, cnt = 0;
  for (int i = 1, t; i <= N; i++) {
    std::cin >> t;
    sum += t;
    MOD[sum % M]++;
  }

  for (int i = 0; i <= M; i++) {
    cnt += (MOD[i] * (MOD[i] - 1)) / 2;
  }

  std::cout << cnt + MOD[0];
}

int main() {
  IO;
  solve();
  return 0;
}
