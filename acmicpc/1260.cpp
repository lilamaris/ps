#include <iostream>
#include <vector>

#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr)
#define N 1000
#define M 10000

struct Node {
  std::vector<int> linked;
};

std::vector<Node> g(N);
std::vector<bool> vst(N);
std::vector<int> vstq(M);

void dfs(int v) {
  vst[v] = true;
  std::cout << v << " ";
  for (int i = 0; i < g[v].linked.size(); i++) {
    int next = g[v].linked[i];
    if (!vst[next]) {
      dfs(next);
    }
  }
}

void bfs(int v) {}

void solve() {
  int n, m, v, src, dst;

  std::cin >> n >> m >> v;

  for (; m--;) {
    std::cin >> src >> dst;
    g[src].linked.push_back(dst);
    g[dst].linked.push_back(src);
  }
  dfs(v);
  std::fill(vst.begin(), vst.end(), false);
  bfs(v);
}

int main() {
  solve();
  return 0;
}
