#include <algorithm>
#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define BIG_NUMBER 987654321
#define MAX 51
#define NOT_VISITED -1
#define WALL '#'
#define EMPTY '.'
#define START '0'
#define EXIT '1'

int board[MAX][MAX];
int dist[MAX][MAX][65];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int N, M;

struct State {
  int r;
  int c;
  short hasKey;
};

int bfs(State start) {
  std::queue<State> Q;
  auto [sr, sc, sHasKey] = start;
  dist[sr][sc][sHasKey] = 0;
  Q.push(start);

  int min_dist = BIG_NUMBER;

  while (!Q.empty()) {
    auto [qr, qc, qHasKey] = Q.front();

    Q.pop();

    if (board[qr][qc] == EXIT) {
      min_dist = std::min(min_dist, dist[qr][qc][qHasKey]);
    }

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nr && nr < N && 0 <= nc && nc < M) {
        char next = board[nr][nc];
        bool canMove = next == EMPTY || next == START || next == EXIT;

        // 그냥 빈공간은 나아가기
        if (canMove && dist[nr][nc][qHasKey] == NOT_VISITED) {
          dist[nr][nc][qHasKey] = dist[qr][qc][qHasKey] + 1;
          Q.push({nr, nc, qHasKey});
        }

        // 열쇠가 있을 때
        if (97 <= next && next < 103) {
          char nCurKey = next - 97 + 1;
          short nHasKey = qHasKey | (1 << nCurKey);
          if (dist[nr][nc][nHasKey] == NOT_VISITED) {
            dist[nr][nc][nHasKey] = dist[qr][qc][qHasKey] + 1;
            Q.push({nr, nc, nHasKey});
          }
        }

        // 문이 있을 때
        if (65 <= next && next < 71) {
          char requiredKey = next - 65 + 1;
          if (qHasKey & (1 << requiredKey)) {
            if (dist[nr][nc][qHasKey] == NOT_VISITED) {
              dist[nr][nc][qHasKey] = dist[qr][qc][qHasKey] + 1;
              Q.push({nr, nc, qHasKey});
            }
          }
        }
      }
    }
  }

  return min_dist;
}

void solve() {
  std::cin >> N >> M;

  State start = {-1, -1, 0};
  std::string x;
  for (int r = 0; r < N; r++) {
    std::cin >> x;
    for (int c = 0; c < M; c++) {
      board[r][c] = x[c];
      if (x[c] == START) {
        start.r = r;
        start.c = c;
      }
    }
  }

  std::fill(&dist[0][0][0], &dist[0][0][0] + (MAX * MAX * 65), NOT_VISITED);

  int result = bfs(start);

  std::cout << (result == BIG_NUMBER ? -1 : result);
}
int main() {
  IO;
  solve();
  return 0;
}
