#include <algorithm>
#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#define MAX 101
#define INF 987654321

int board[MAX][MAX];
int cost[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int T, N;

void bfs(std::pair<int, int> s) {
  std::queue<std::pair<int, int>> Q;
  Q.push(s);

  while (!Q.empty()) {
    auto [qx, qy] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = qx + dx[i];
      int ny = qy + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        int c = cost[qy][qx] + board[ny][nx];
        if (c < cost[ny][nx]) {
          Q.push({nx, ny});
          cost[ny][nx] = c;
        }
      }
    }
  }
}

void solve() {
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
      std::fill(cost[i], cost[i] + N, INF);
    }

    cost[0][0] = 0;

    std::string x;

    for (int i = 0; i < N; i++) {
      std::cin >> x;

      for (int j = 0; j < N; j++) {
        board[i][j] = x[j] - '0';
      }
    }

    bfs({0, 0});

    std::cout << "#" << t << " " << cost[N - 1][N - 1] << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
