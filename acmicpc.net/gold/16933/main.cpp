#include <iostream>
#include <queue>
#include <tuple>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001
#define MAX_K 11
#define NOT_VISITED -1
#define BIG_NUMBER 987654321
#define DAY 1
#define NIGHT 0

int board[MAX][MAX];
int dist[MAX][MAX][MAX_K][2];

int N, M, K;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs(int r, int c, int k) {
  std::queue<std::tuple<int, int, int, int>> Q;
  Q.push({r, c, k, DAY});
  dist[r][c][k][DAY] = 1;

  while (!Q.empty()) {
    auto [qr, qc, qk, qd] = Q.front();
    Q.pop();

    bool isDay = qd == DAY;

    if (dist[qr][qc][qk][!isDay] == NOT_VISITED) {
      dist[qr][qc][qk][!isDay] = dist[qr][qc][qk][isDay] + 1;
      Q.push({qr, qc, qk, !isDay});
    }

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nr && nr < N && 0 <= nc && nc < M) {
        bool isWall = board[nr][nc] == 1;

        // 벽 아님, 방문한 적 없음 (지금이 낮이라면 밤에, 밤이라면 낮에)
        if (!isWall && dist[nr][nc][qk][!isDay] == NOT_VISITED) {
          dist[nr][nc][qk][!isDay] = dist[qr][qc][qk][isDay] + 1;
          Q.push({nr, nc, qk, !isDay});
        }

        // 벽이고, 부술 기회 있음, 방문한 적 없음
        if (isWall && qk < K && dist[nr][nc][qk + 1][!isDay] == NOT_VISITED) {
          if (isDay) {
            // 지금이 낮이면 : 부수고 나아갈 수 있음
            dist[nr][nc][qk + 1][NIGHT] = dist[qr][qc][qk][DAY] + 1;
            Q.push({nr, nc, qk + 1, NIGHT});
          }
        }
      }
    }
  }
}

void solve() {
  std::cin >> N >> M >> K;

  std::string x;
  for (int r = 0; r < N; r++) {
    std::cin >> x;
    for (int c = 0; c < M; c++) {
      board[r][c] = x[c] - '0';
    }
  }

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      for (int k = 0; k <= K; k++) {
        std::fill(dist[r][c][k], dist[r][c][k] + 2, -1);
      }
    }
  }

  bfs(0, 0, 0);

  int result = BIG_NUMBER;
  for (int k = 0; k <= K; k++) {
    for (int d = 0; d < 2; d++) {
      if (dist[N - 1][M - 1][k][d] != NOT_VISITED) {
        result = std::min(result, dist[N - 1][M - 1][k][d]);
      }
    }
  }

  std::cout << (result == BIG_NUMBER ? -1 : result);
}

int main() {
  IO;
  solve();
  return 0;
}
