#include <iostream>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100001
int N, Q;

void solve() {
  std::cin >> N;

  std::vector<int> sheet(N + 1, 0);
  std::vector<int> prefix(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;
    sheet[i] = x;
    bool miss = sheet[i - 1] > sheet[i];
    prefix[i] = prefix[i - 1] + (miss ? 1 : 0);
  }

  std::cin >> Q;

  for (int i = 0; i < Q; i++) {
    int x, y;
    std::cin >> x >> y;

    std::cout << prefix[y - 1] - prefix[x - 1] << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
