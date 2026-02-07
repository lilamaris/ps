#include <algorithm>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

int N;
int tree[100000];
int dist[100000];

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0)
    return b;
  return gcd(b, r);
}

void solve() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> tree[i];
  }

  std::sort(tree, tree + N);

  for (int i = 0; i < N - 1; i++) {
    dist[i] = tree[i + 1] - tree[i];
  }

  int treeGcd = dist[0];
  for (int i = 1; i < N - 1; i++) {
    treeGcd = gcd(treeGcd, dist[i]);
  }

  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    count += (dist[i] / treeGcd) - 1;
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
