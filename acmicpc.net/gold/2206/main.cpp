#include <iostream>
#include <queue>
#include <tuple>

#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001
#define NOT_VISITED -1

int board[MAX][MAX];
int dist[MAX][MAX][2];

int N, M;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void bfs(int r, int c, int broken) {
  dist[r][c][0] = dist[r][c][1] = 1;
  std::queue<std::tuple<int, int, int>> Q;
  Q.push({r, c, broken});

  while (!Q.empty()) {
    auto [qr, qc, qb] = Q.front();

    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nc && nc < M && 0 <= nr && nr < N) {
        bool isWall = board[nr][nc] == 1;

        if (!isWall && dist[nr][nc][qb] == NOT_VISITED) {
          dist[nr][nc][qb] = dist[qr][qc][qb] + 1;
          Q.push({nr, nc, qb});
        }
        if (isWall && qb == 0 && dist[nr][nc][qb + 1] == NOT_VISITED) {
          dist[nr][nc][qb + 1] = dist[qr][qc][qb] + 1;
          Q.push({nr, nc, qb + 1});
        }
      }
    }
  }
}

void solve() {
  std::cin >> N >> M;

  std::string x;
  for (int r = 0; r < N; r++) {
    std::cin >> x;
    for (int c = 0; c < M; c++) {
      board[r][c] = x[c] - 48;
    }
  }

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      std::fill(dist[r][c], dist[r][c] + 2, NOT_VISITED);
    }
  }

  bfs(0, 0, 0);

  auto r = dist[N - 1][M - 1];

  if (r[0] == NOT_VISITED)
    std::cout << r[1];
  else if (r[1] == NOT_VISITED)
    std::cout << r[0];
  else
    std::cout << std::min(r[0], r[1]);
}

int main() {
  IO;
  solve();
  return 0;
}
