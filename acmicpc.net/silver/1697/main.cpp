#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100001

int N, K;
bool visited[MAX];

int monitor[MAX];

void bfs(int n) {
  std::queue<std::pair<int, int>> Q;
  visited[n] = true;
  Q.push({n, 0});

  monitor[n] = 0;

  while (!Q.empty()) {
    auto [x, count] = Q.front();
    Q.pop();

    if (x == K) {
      std::cout << count << '\n';
      return;
    }

    if (0 <= x + 1 && x + 1 < MAX && !visited[x + 1]) {
      visited[x + 1] = true;
      Q.push({x + 1, count + 1});
      monitor[x + 1] = count + 1;
    }

    if (0 <= x - 1 && x - 1 < MAX && !visited[x - 1]) {
      visited[x - 1] = true;
      Q.push({x - 1, count + 1});
      monitor[x - 1] = count + 1;
    }

    if (0 <= x * 2 && x * 2 < MAX && !visited[x * 2]) {
      visited[x * 2] = true;
      Q.push({x * 2, count + 1});
      monitor[x * 2] = count + 1;
    }
  }
}

void solve() {
  std::cin >> N >> K;

  bfs(N);
}

int main() {
  IO;
  solve();
  return 0;
}
