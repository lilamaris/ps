#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100

int N;
int A[MAX];

void solve() {
  int t;
  std::cin >> t;

  int x;
  for (int i = 0; i < t; i++) {
    std::cin >> x;
  }
}

void initial() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
