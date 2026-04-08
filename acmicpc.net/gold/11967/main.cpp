#include <iostream>
#include <queue>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 101

std::vector<std::pair<int, int>> switchs[MAX][MAX];
bool light[MAX][MAX];
bool visited[MAX][MAX];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int N, M;

struct State {
  int r;
  int c;
};

int bfs(State start) {
  std::queue<State> Q;
  auto [sr, sc] = start;
  light[sr][sc] = true;
  visited[sr][sc] = true;

  Q.push(start);

  int result = 1;

  while (!Q.empty()) {
    auto [qr, qc] = Q.front();
    Q.pop();

    // 해당 방에 스위치가 있으면, 불을 켠다.
    for (auto sw : switchs[qr][qc]) {
      auto [sw_r, sw_c] = sw;
      // 이미 스위치가 불을 켤 수 있는 방의 불이 켜져 있으면 생략
      if (light[sw_r][sw_c]) {
        continue;
      }

      // 스위치가 불을 켤 수 있는 방의 불이 꺼져 있으면 불을 켠다
      light[sw_r][sw_c] = true;
      result++;

      for (int i = 0; i < 4; i++) {
        int nr = sw_r + dr[i];
        int nc = sw_c + dc[i];

        // 만약 스위치로 불을 켠 방이 방문 경로 상 접근할 수 있는 방이고,
        // 그 방을 방문한 적이 없다면, 방문한다
        if (0 < nr && nr <= N && 0 < nc && nc <= N) {
          if (visited[nr][nc] && !visited[sw_r][sw_c]) {
            visited[sw_r][sw_c] = true;
            Q.push({sw_r, sw_c});
          }
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      int nr = qr + dr[i];
      int nc = qc + dc[i];

      if (0 < nr && nr <= N && 0 < nc && nc <= N) {
        // 불이 켜져있고, 방문하지 않았으면, 방문한다
        if (light[nr][nc] && !visited[nr][nc]) {
          visited[nr][nc] = true;
          Q.push({nr, nc});
        }
      }
    }
  }

  return result;
}

void solve() {
  std::cin >> N >> M;

  int r, c, sw_r, sw_c;
  for (int i = 0; i < M; i++) {
    std::cin >> r >> c >> sw_r >> sw_c;
    switchs[r][c].push_back({sw_r, sw_c});
  }

  State start = {1, 1};
  std::cout << bfs(start);
}

int main() {
  IO;
  solve();
  return 0;
}
