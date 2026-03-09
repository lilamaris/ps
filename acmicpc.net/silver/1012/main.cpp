#include <cstring>
#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 51

int T, M, N, K, result = 0, map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y) {
  std::queue<std::pair<int, int>> Q;
  Q.push({x, y});
  visited[y][x] = true;

  while (!Q.empty()) {
    auto [qx, qy] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = qx + dx[i];
      int ny = qy + dy[i];

      if (0 <= nx && 0 <= ny && nx < M && ny < N && !visited[ny][nx] &&
          map[ny][nx] == 1) {
        Q.push({nx, ny});
        visited[ny][nx] = true;
      }
    }
  }
}

void solve() {
  std::cin >> T;

  while (T--) {
    std::cin >> M >> N >> K;

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    result = 0;

    int x, y;
    for (int i = 0; i < K; i++) {
      std::cin >> x >> y;

      map[y][x] = 1;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j] == 1 && !visited[i][j]) {
          bfs(j, i);
          result++;
        }
      }
    }

    std::cout << result << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
