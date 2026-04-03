#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

int H, W, D;

int board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dh[6] = {1, -1, 0, 0, 0, 0};
int dw[6] = {0, 0, 1, -1, 0, 0};
int dd[6] = {0, 0, 0, 0, 1, -1};

struct Pos {
  int depth;
  int height;
  int width;
};

std::queue<struct Pos> Q;

void bfs() {
  int nd, nh, nw;

  while (!Q.empty()) {
    auto [qd, qh, qw] = Q.front();
    Q.pop();

    for (int i = 0; i < 6; i++) {
      nd = qd + dd[i];
      nh = qh + dh[i];
      nw = qw + dw[i];

      if (0 <= nd && nd < D && 0 <= nh && nh < H && 0 <= nw && nw < W) {
        if (board[nd][nh][nw] == 0 && dist[nd][nh][nw] == -1) {
          dist[nd][nh][nw] = dist[qd][qh][qw] + 1;
          Q.push({nd, nh, nw});
        }
      }
    }
  }
}

void solve() {
  std::cin >> W >> H >> D;

  std::fill(dist[0][0], dist[0][0] + (MAX * MAX * MAX), -1);

  for (int i = 0; i < D; i++) {
    for (int j = 0; j < H; j++) {
      for (int k = 0; k < W; k++) {
        std::cin >> board[i][j][k];

        if (board[i][j][k] == 1) {
          dist[i][j][k] = 0;
          Q.push({i, j, k});
        }
      }
    }
  }

  bfs();

  int max = 0;

  for (int i = 0; i < D; i++) {
    for (int j = 0; j < H; j++) {
      for (int k = 0; k < W; k++) {
        if (board[i][j][k] == 0) {
          if (dist[i][j][k] == -1) {
            std::cout << -1;
            return;
          }
          max = std::max(max, dist[i][j][k]);
        }
      }
    }
  }

  std::cout << max;
}

int main() {
  IO;
  solve();
  return 0;
}
