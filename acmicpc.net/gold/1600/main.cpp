#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 201
#define MAX_K 31
#define NOT_VISITED -1
#define BIG_NUMBER 987654321

int board[MAX][MAX];
int dist[MAX][MAX][MAX_K];

int h_dh[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int h_dw[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n_dh[4] = {0, 0, 1, -1};
int n_dw[4] = {1, -1, 0, 0};

int K, W, H;

void bfs(int h, int w, int k) {
  std::queue<std::tuple<int, int, int>> Q;
  dist[h][w][k] = 0;
  Q.push({h, w, k});

  while (!Q.empty()) {
    auto [qh, qw, qk] = Q.front();
    Q.pop();

    // 단순 사방면으로 이동할 때
    for (int i = 0; i < 4; i++) {
      int n_nh = qh + n_dh[i];
      int n_nw = qw + n_dw[i];

      if (0 <= n_nh && n_nh < H && 0 <= n_nw && n_nw < W) {
        bool isWall = board[n_nh][n_nw] == 1;

        if (!isWall && dist[n_nh][n_nw][qk] == NOT_VISITED) {
          dist[n_nh][n_nw][qk] = dist[qh][qw][qk] + 1;
          Q.push({n_nh, n_nw, qk});
        }
      }
    }

    // 말처럼 이동할 때
    for (int i = 0; i < 8; i++) {
      int h_nh = qh + h_dh[i];
      int h_nw = qw + h_dw[i];

      if (0 <= h_nh && h_nh < H && 0 <= h_nw && h_nw < W) {
        bool isWall = board[h_nh][h_nw] == 1;

        if (!isWall && qk < K && dist[h_nh][h_nw][qk + 1] == NOT_VISITED) {
          dist[h_nh][h_nw][qk + 1] = dist[qh][qw][qk] + 1;
          Q.push({h_nh, h_nw, qk + 1});
        }
      }
    }
  }
}

void solve() {
  std::cin >> K;

  std::cin >> W >> H;

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      std::cin >> board[h][w];
    }
  }

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      std::fill(dist[h][w], dist[h][w] + K + 1, NOT_VISITED);
    }
  }

  bfs(0, 0, 0);

  int min_dist = BIG_NUMBER;

  for (int k = 0; k <= K; k++) {
    int result = dist[H - 1][W - 1][k];
    if (result != NOT_VISITED)
      min_dist = std::min(min_dist, result);
  }

  std::cout << (min_dist == BIG_NUMBER ? -1 : min_dist);
}

int main() {
  IO;
  solve();
  return 0;
}
