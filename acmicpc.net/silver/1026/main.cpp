#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

int a[100];
int b[100];

void solve() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::sort(a, a + n);
  std::sort(b, b + n);

  std::reverse(a, a + n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i] * b[i];
  }

  std::cout << sum;
}

int main() {
  IO;
  solve();
  return 0;
}
