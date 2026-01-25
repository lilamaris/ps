#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 8

int arr[MAX] = {
    0,
};
bool visit[MAX] = {
    0,
};

void print(int cnt) {
  for (int i = 0; i < cnt; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void dfs(int n, int m, int cnt) {
  if (cnt == m) {
    print(cnt);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      visit[i] = true;
      arr[cnt] = i;
      dfs(n, m, cnt + 1);
      visit[i] = false;
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  dfs(n, m, 0);
}

int main() {
  IO;
  solve();
  return 0;
}
