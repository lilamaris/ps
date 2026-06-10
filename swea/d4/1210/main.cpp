#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define GOAL 2
#define SIZE 100

int T = 10;

int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dc[2] = {1, -1};

void bfs(std::pair<int, int> end) {
  std::queue<std::pair<int, int>> Q;
  Q.push(end);
  visited[end.first][end.second] = true;

  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    if (qr == 0)
      break;

    bool hasCross = false;

    for (int d = 0; d < 2; d++) {
      int nc = qc + dc[d];

      if (nc < 0 || SIZE <= nc)
        continue;

      if (visited[qr][nc])
        continue;

      if (board[qr][nc] != 1)
        continue;

      hasCross = true;
      visited[qr][nc] = true;
      Q.push({qr, nc});
    }

    if (!hasCross) {
      int nr = qr - 1;

      if (nr < 0 || SIZE <= nr)
        continue;

      if (visited[nr][qc])
        continue;

      if (board[nr][qc] != 1)
        continue;

      visited[nr][qc] = true;
      Q.push({nr, qc});
    }
  }
}

void solve() {
  int t, x;
  std::pair<int, int> end;

  while (T--) {
    std::cin >> t;

    for (int row = 0; row < SIZE; row++) {
      std::fill(visited[row], visited[row] + SIZE, false);
    }

    for (int row = 0; row < SIZE; row++) {
      for (int col = 0; col < SIZE; col++) {
        std::cin >> x;

        board[row][col] = x;
        if (x == GOAL)
          end = {row, col};
      }
    }

    bfs(end);

    std::cout << "#" << t << " ";
    for (int col = 0; col < SIZE; col++) {
      if (visited[0][col]) {
        std::cout << col << '\n';
      }
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
