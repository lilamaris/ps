#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <tuple>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001
#define MAX_K 11
#define NOT_VISITED -1
#define BIG_NUMBER 987654321

int board[MAX][MAX];
int dist[MAX][MAX][MAX_K];

int N, M, K;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void printDist() {
  for (int r = 0; r < N; r++) {
    for (int k = 0; k < K; k++) {
      for (int c = 0; c < M; c++) {
        std::cout << std::setw(2) << dist[r][c][k] << ' ';
      }

      for (int i = 0; i < 5; i++) {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << "----- END -----\n\n\n";
}

void bfs(int r, int c, int k) {
  std::queue<std::tuple<int, int, int>> Q;
  dist[r][c][k] = 1;
  Q.push({r, c, k});

  while (!Q.empty()) {
    auto [qr, qc, qk] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nc && nc < M && 0 <= nr && nr < N) {
        bool isWall = board[nr][nc];
        if (!isWall && dist[nr][nc][qk] == NOT_VISITED) {
          dist[nr][nc][qk] = dist[qr][qc][qk] + 1;
          Q.push({nr, nc, qk});
        }
        if (isWall && qk + 1 < K && dist[nr][nc][qk + 1] == NOT_VISITED) {
          dist[nr][nc][qk + 1] = dist[qr][qc][qk] + 1;
          Q.push({nr, nc, qk + 1});
        }
      }
    }
  }
}

void solve() {
  std::cin >> N >> M >> K;

  // K = 1일 때는 한번도 안 부수고 간 dist와 한 번 부수고 간 dist로 총 2개의
  // 상태가 있을 수 있다 그래서 K를 바탕으로 dist를 초기화 하기 때문에 K에 1을
  // 더한다
  K++;
  std::string x;
  for (int r = 0; r < N; r++) {
    std::cin >> x;
    for (int c = 0; c < M; c++) {
      board[r][c] = x[c] - '0';
    }
  }

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      std::fill(dist[r][c], dist[r][c] + K, NOT_VISITED);
    }
  }

  bfs(0, 0, 0);

  int result = BIG_NUMBER;
  for (int k = 0; k < K; k++) {
    if (dist[N - 1][M - 1][k] != NOT_VISITED) {
      result = std::min(result, dist[N - 1][M - 1][k]);
    }
  }

  std::cout << (result == BIG_NUMBER ? -1 : result);
}

int main() {
  IO;
  solve();
  return 0;
}
