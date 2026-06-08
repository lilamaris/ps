#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)
#define MAX 101
#define INF 987654321

int dist[MAX][MAX];
int board[MAX][MAX];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int T, N;

struct Node {
  int cost;
  int row;
  int col;

  bool operator<(const Node &other) const { return this->cost > other.cost; }
};

void dijkstra(std::pair<int, int> start, std::pair<int, int> end) {
  std::priority_queue<Node> pq;
  pq.push({0, start.first, start.second});
  dist[start.first][start.second] = 0;

  while (!pq.empty()) {
    auto [curCost, qr, qc] = pq.top();
    pq.pop();

    if (curCost > dist[qr][qc]) {
      continue;
    }

    if (qr == end.first && qc == end.second) {
      break;
    }

    for (int d = 0; d < 4; d++) {
      int nr = qr + dr[d];
      int nc = qc + dc[d];

      if (nr < 0 || N <= nr || nc < 0 || N <= nc) {
        continue;
      }

      int nextCost = curCost + board[nr][nc];

      if (nextCost < dist[nr][nc]) {
        dist[nr][nc] = nextCost;
        pq.push({nextCost, nr, nc});
      }
    }
  }
}

void solve() {
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> N;

    std::pair<int, int> startPos = {0, 0};
    std::pair<int, int> endPos = {N - 1, N - 1};

    for (int row = 0; row < N; row++) {
      std::fill(dist[row], dist[row] + N, INF);
    }

    std::string x;

    for (int row = 0; row < N; row++) {
      std::cin >> x;

      for (int col = 0; col < N; col++) {
        board[row][col] = x[col] - '0';
      }
    }

    dijkstra(startPos, endPos);

    std::cout << "#" << t << " " << dist[endPos.first][endPos.second] << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
