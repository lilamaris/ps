#include <algorithm>
#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

int N;
int board[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

std::vector<std::pair<int, int>> area_mark(int r, int c, int area) {
  board[r][c] = area;
  visited[r][c] = true;
  std::queue<std::pair<int, int>> Q;
  std::vector<std::pair<int, int>> A;
  Q.push({r, c});

  // 같은 섬으로 라벨링 되는 위치는 벡터 넣어서 반환
  // multi source BFS에서 한번에 큐에 넣으려고
  A.push_back({r, c});

  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nc && nc < N && 0 <= nr && nr < N) {
        if (!visited[nr][nc] && board[nr][nc] == 1) {
          board[nr][nc] = area;
          visited[nr][nc] = true;
          Q.push({nr, nc});
          A.push_back({nr, nc});
        }
      }
    }
  }

  return A;
}

int find_path(std::vector<std::pair<int, int>> &area) {
  int dist[N][N];
  int min_path = N * 2;
  for (int r = 0; r < N; r++) {
    std::fill(dist[r], dist[r] + N, 0);
  }

  std::queue<std::pair<int, int>> Q;
  for (auto [r, c] : area) {
    Q.push({r, c});
    visited[r][c] = true;
  }

  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 <= nc && nc < N && 0 <= nr && nr < N) {
        if (!visited[nr][nc]) {
          dist[nr][nc] = dist[qr][qc] + 1;
          visited[nr][nc] = true;

          // 바다인 지점은 다리를 놓고 또 나아가야하는 위치
          if (board[nr][nc] == 0) {
            Q.push({nr, nc});
          }
          // 탐색을 시작한 Source 섬의 라벨이 아닌 섬 번호만 조건에 넣고 싶은데,
          // 그러러면 초기 시작 위치를 큐에 넣을 때 탐색 시작 섬의 라벨을 따로
          // 보관해야함 근데 탐색 시작 후보로 넘어오는 area 파라미터의 모든
          // pair가 전부 동일한 섬 라벨을 가리킨다는 보장을 할 수 없음 라벨링
          // 로직 자체가 동일한 섬 라벨을 가리키는 페어만 넣어주긴 하지만 딱히
          // 이 함수에서 그걸 검증하지 않으니까, 일반적으로 사용 가능한 함수는
          // 아님 지금은 단순히 처음 큐에 넣을 때 visited도 true로 해주므로,
          // visited = false이면서 0이 아닌 위치는 Source 섬이 아닌 다른
          // 섬이라는 것을 알 수는 있음
          else {
            min_path = std::min(min_path, dist[qr][qc]);
          }
        }
      }
    }
  }

  return min_path;
}

void solve() {
  std::cin >> N;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      std::cin >> board[r][c];
    }
  }

  std::vector<std::vector<std::pair<int, int>>> areas;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (board[r][c] == 1 && !visited[r][c]) {
        areas.push_back(area_mark(r, c, areas.size() + 1));
      }
    }
  }

  int min_path = N * 2;
  for (auto area : areas) {
    for (int r = 0; r < N; r++) {
      std::fill(visited[r], visited[r] + N, false);
    }
    min_path = std::min(min_path, find_path(area));
  }

  std::cout << min_path;
}

int main() {
  IO;
  solve();
  return 0;
}
