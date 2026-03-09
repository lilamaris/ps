#include <cstring>
#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <queue>

#define MAX 301

int dist[MAX][MAX];
int T, L, SC, SR, DC, DR;

int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void bfs(int c, int r) {
  std::queue<std::pair<int, int>> Q;
  Q.push({c, r});
  dist[r][c] = 1;

  while (!Q.empty()) {
    auto [qc, qr] = Q.front();
    Q.pop();

    if (qc == DC && qr == DR) {
      std::cout << dist[qr][qc] - 1 << '\n';
      break;
    }

    for (int i = 0; i < 8; i++) {
      int nc = qc + dc[i];
      int nr = qr + dr[i];

      if (0 <= nc && 0 <= nr && nc < L && nr < L && dist[nr][nc] == 0) {
        Q.push({nc, nr});
        dist[nr][nc] = dist[qr][qc] + 1;
      }
    }
  }
}

void solve() {
  std::cin >> T;

  while (T--) {
    std::cin >> L >> SC >> SR >> DC >> DR;
    memset(dist, 0, sizeof(dist));

    bfs(SC, SR);
  }
}

int main() {
  IO;
  solve();
  return 0;
}
