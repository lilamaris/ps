#include <iostream>
#include <queue>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 501
#define DEP_LIMIT 2

std::vector<int> V[MAX];
int dist[MAX];
int N, M;

void BFS(int start) {
  std::queue<int> Q;
  dist[start] = 0;

  Q.push(start);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (auto next : V[cur]) {
      if (dist[next] == -1) {
        dist[next] = dist[cur] + 1;
        if (dist[next] <= DEP_LIMIT) {
          Q.push(next);
        }
      }
    }
  }
}

void solve() {
  std::cin >> N;
  std::cin >> M;

  std::fill(dist, dist + MAX, -1);

  int a, b;
  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  BFS(1);

  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (0 < dist[i] && dist[i] <= DEP_LIMIT)
      count++;
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
