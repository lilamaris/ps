#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 8

int arr[MAX] = {
    0,
};

int n, m;

void print() {
  for (int i = 0; i < m; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void dfs(int i, int cnt) {
  if (cnt == m) {
    print();
    return;
  }

  for (; i <= n; i++) {
    arr[cnt] = i;
    dfs(i, cnt + 1);
  }
}

void solve() {
  std::cin >> n >> m;

  dfs(1, 0);
}

int main() {
  IO;
  solve();
  return 0;
}
