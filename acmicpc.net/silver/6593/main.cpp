#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

int N;

int board[MAX][MAX];
bool visited[MAX][MAX];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs(int r, int c, int limit) {
  std::queue<std::pair<int, int>> Q;
  Q.push({r, c});
  visited[r][c] = true;

  int nr, nc;
  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      nr = qr + dr[i];
      nc = qc + dc[i];

      if (0 <= nr && nr < N && 0 <= nc && nc < N) {
        if (board[nr][nc] > limit && !visited[nr][nc]) {
          visited[nr][nc] = true;
          Q.push({nr, nc});
        }
      }
    }
  }
}

void solve() {
  std::cin >> N;

  int maxHeight = 0;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      std::cin >> board[r][c];

      maxHeight = std::max(maxHeight, board[r][c]);
    }
  }

  int maxArea = 0;
  for (int l = 0; l < maxHeight; l++) {
    std::fill(visited[0], visited[0] + (MAX * MAX), false);

    int area = 0;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (board[r][c] > l && !visited[r][c]) {
          area++;
          bfs(r, c, l);
        }
      }
    }

    maxArea = std::max(maxArea, area);
  }

  std::cout << maxArea;
}

int main() {
  IO;
  solve();
  return 0;
}
