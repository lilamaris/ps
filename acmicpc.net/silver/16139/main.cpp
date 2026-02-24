#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 200000

int Q, A[26][MAX];

void solve() {
  std::string s;

  std::cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (i != 0) {
      for (int j = 0; j < 26; j++) {
        A[j][i] = A[j][i - 1];
      }
    }

    A[s[i] - 'a'][i]++;
  }

  std::cin >> Q;

  char c;
  int i, l, r;
  while (Q--) {
    std::cin >> c >> l >> r;
    i = c - 'a';
    if (l == 0) {
      std::cout << A[i][r];
    } else {
      std::cout << A[i][r] - A[i][l - 1];
    }

    std::cout << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
