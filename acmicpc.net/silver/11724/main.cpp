#include <iostream>
#include <queue>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001

int N, M;
std::vector<int> V[MAX];
bool visited[MAX];

void BFS(int s) {
  std::queue<int> Q;
  visited[s] = true;

  Q.push(s);

  while (!Q.empty()) {
    int qs = Q.front();
    Q.pop();

    for (auto &next : V[qs]) {
      if (!visited[next]) {
        visited[next] = true;
        Q.push(next);
      }
    }
  }
}

void DFS(int s) {
  visited[s] = true;

  for (auto &next : V[s]) {
    if (!visited[next]) {
      DFS(next);
    }
  }
}

void solve() {
  std::cin >> N >> M;

  int u, v;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }

  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      count++;
      DFS(i);
    }
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
