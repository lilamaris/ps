#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

int N, M;
std::queue<std::pair<int, int>> Q;
bool visited[MAX][MAX];
int map[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
  Q.push({x, y});
  visited[y][x] = true;

  while (!Q.empty()) {
    auto [qx, qy] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = qx + dx[i];
      int ny = qy + dy[i];

      if (0 <= nx && 0 <= ny && nx < M && ny < N) {
        if (!visited[ny][nx] && map[ny][nx] == 1) {
          visited[ny][nx] = true;
          Q.push({nx, ny});
          map[ny][nx] += map[qy][qx];
        }
      }
    }
  }
}

void solve() {
  std::cin >> N >> M;

  std::string x;
  for (int i = 0; i < N; i++) {
    std::cin >> x;

    for (int j = 0; j < M; j++) {
      map[i][j] = x[j] - '0';
    }
  }

  dfs(0, 0);

  std::cout << map[N - 1][M - 1];
}

int main() {
  IO;
  solve();
  return 0;
}
