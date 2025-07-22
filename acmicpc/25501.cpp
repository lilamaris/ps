#include <cstring>
#include <iostream>

int c = 0;

int recursion(const char *s, int l, int r) {
  c++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

void solve() {
  int n, k;
  char s[1001];

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    c = 0;
    std::cin >> s;
    std::cout << recursion(s, 0, strlen(s) - 1) << " " << c << std::endl;
  }
}

int main() {
  solve();
  return 0;
}
