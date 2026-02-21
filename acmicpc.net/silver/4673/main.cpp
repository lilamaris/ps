#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

int digitSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

bool isSelf(int n) {
  int sum;
  for (int i = 1; i < n; i++) {
    sum = i + digitSum(i);
    if (n == sum)
      return false;
  }
  return true;
}

void solve() {
  for (int i = 1; i <= 10000; i++) {
    if (isSelf(i)) {
      std::cout << i << '\n';
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
