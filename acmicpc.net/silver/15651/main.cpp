#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#define MAX 8

int n, m;
int arr[MAX] = {
    0,
};

void print() {
  for (int i = 0; i < m; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void dfs(int cnt) {
  if (cnt == m) {
    print();
    return;
  }

  for (int i = 1; i <= n; i++) {
    arr[cnt] = i;
    dfs(cnt + 1);
  }
}

void solve() {
  std::cin >> n >> m;
  dfs(0);
}

int main() {
  IO;
  solve();
  return 0;
}
