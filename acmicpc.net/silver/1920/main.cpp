#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100000

int N, M, A[MAX];

int find(int target, int *arr, std::size_t n) {
  int l = 0, r = n - 1, m;

  while (l <= r) {
    m = (l + r) / 2;

    std::cout << "mid: " << m << '\n';
    if (target == arr[m])
      return 1;

    if (target < arr[m])
      r = m - 1;
    else
      l = m + 1;
  }

  return 0;
}

void solve() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::sort(A, A + N);

  std::cin >> M;

  int target;
  for (int i = 0; i < M; i++) {
    std::cin >> target;
    std::cout << find(target, A, N) << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
