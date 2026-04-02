#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001

int R, C;

int map[MAX][MAX];
int dist[MAX][MAX];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int row, int col) {
  std::queue<std::pair<int, int>> Q;
  Q.push({row, col});

  int nr, nc;
  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      nr = qr + dr[i];
      nc = qc + dc[i];

      if (0 <= nr && nr < R && 0 <= nc && nc < C) {
        if (map[nr][nc] == 1 && dist[nr][nc] == -1) {
          Q.push({nr, nc});
          dist[nr][nc] = dist[qr][qc] + 1;
        }
      }
    }
  }
}

void solve() {
  std::cin >> R >> C;

  int sr, sc;

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      std::cin >> map[r][c];
      if (map[r][c] == 2) {
        sr = r;
        sc = c;
        dist[r][c] = 0;
      } else if (map[r][c] == 0) {
        dist[r][c] = 0;
      } else {
        dist[r][c] = -1;
      }
    }
  }

  bfs(sr, sc);

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      std::cout << dist[r][c] << ' ';
    }

    std::cout << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
