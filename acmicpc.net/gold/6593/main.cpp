#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 31
#define NOT_VISITED -1

#define EMPTY '.'
#define WALL '#'
#define START 'S'
#define END 'E'

char board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dl[6] = {1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {0, 0, 0, 0, 1, -1};

int L, R, C;

struct State {
  int l;
  int r;
  int c;
};

void bfs(State start) {
  std::queue<State> Q;

  auto [sl, sr, sc] = start;
  dist[sl][sr][sc] = 0;
  Q.push(start);

  while (!Q.empty()) {
    auto [ql, qr, qc] = Q.front();
    Q.pop();

    if (board[ql][qr][qc] == END) {
      return;
    }

    for (int i = 0; i < 6; i++) {
      int nl = ql + dl[i];
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nl && nl < L && 0 <= nr && nr < R && 0 <= nc && nc < C) {
        bool isWall = board[nl][nr][nc] == WALL;

        if (!isWall && dist[nl][nr][nc] == NOT_VISITED) {
          dist[nl][nr][nc] = dist[ql][qr][qc] + 1;
          Q.push({nl, nr, nc});
        }
      }
    }
  }
}

void solve() {
  while (true) {
    std::cin >> L >> R >> C;

    if (L == R && R == C && C == 0) {
      return;
    }

    State start, end;
    std::string x;
    for (int l = 0; l < L; l++) {
      for (int r = 0; r < R; r++) {
        std::cin >> x;
        for (int c = 0; c < C; c++) {
          board[l][r][c] = x[c];
          if (x[c] == START) {
            start = {l, r, c};
          } else if (x[c] == END) {
            end = {l, r, c};
          }
        }
      }
    }

    for (int l = 0; l < L; l++) {
      for (int r = 0; r < R; r++) {
        std::fill(dist[l][r], dist[l][r] + C, NOT_VISITED);
      }
    }

    bfs(start);

    auto [el, er, ec] = end;
    int result = dist[el][er][ec];
    if (result == NOT_VISITED)
      std::cout << "Trapped!\n";
    else
      std::cout << "Escaped in " << result << " minute(s).\n";
  }
}

int main() {
  IO;
  solve();
  return 0;
}
