#include <algorithm>
#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

int N, M, K;
bool visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int bfs(int x, int y) {
  std::queue<std::pair<int, int>> Q;
  Q.push({x, y});
  visited[y][x] = true;
  int space = 1, nx, ny;

  while (!Q.empty()) {
    auto [qx, qy] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      nx = qx + dx[i];
      ny = qy + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (!visited[ny][nx]) {
          visited[ny][nx] = true;
          Q.push({nx, ny});
          space++;
        }
      }
    }
  }

  return space;
}

int recursive_dfs(int x, int y) {
  visited[y][x] = true;
  int area = 1;

  int nx, ny;
  for (int i = 0; i < 4; i++) {
    nx = x + dx[i];
    ny = y + dy[i];
    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
      if (!visited[ny][nx]) {
        area += recursive_dfs(nx, ny);
      }
    }
  }

  return area;
  ;
}

void solve() {
  std::cin >> M >> N >> K;

  int sx, sy, ex, ey;

  std::vector<int> results;

  for (int i = 0; i < K; i++) {
    std::cin >> sx >> sy >> ex >> ey;

    for (int i = sy; i < ey; i++) {
      for (int j = sx; j < ex; j++) {
        visited[i][j] = true;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        int space = recursive_dfs(j, i);
        results.push_back(space);
      }
    }
  }

  std::sort(results.begin(), results.end());

  std::cout << results.size() << '\n';
  for (auto &e : results) {
    std::cout << e << ' ';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
