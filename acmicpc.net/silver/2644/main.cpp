#include <iostream>
#include <queue>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

std::vector<int> V[MAX];
int dist[MAX];
int N, M, S, D;
int result = -1;

void BFS(int source, int dest) {
  std::queue<int> Q;
  dist[source] = 0;
  Q.push(source);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    if (cur == dest) {
      result = dist[cur];
      break;
    }

    for (auto next : V[cur]) {
      if (dist[next] == -1) {
        Q.push(next);
        dist[next] = dist[cur] + 1;
      }
    }
  }
}

void solve() {
  std::cin >> N;
  std::cin >> S >> D;
  std::cin >> M;

  std::fill(dist, dist + N + 1, -1);
  int u, v;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    std::cout << "V #" << i << " -> ";

    for (auto v : V[i]) {
      std::cout << v << " ";
    }
    std::cout << '\n';
  }

  BFS(S, D);

  std::cout << result;
}

int main() {
  IO;
  solve();
  return 0;
}
