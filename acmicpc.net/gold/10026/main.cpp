#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 100

int N;
char A[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void applyG2R() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] == 'G')
        A[i][j] = 'R';
    }
  }
}

void bfs(int x, int y) {
  visit[x][y] = true;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(x, y));
  int qx, qy, nx, ny;
  while (!q.empty()) {
    qx = q.front().first;
    qy = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      nx = qx + dx[i];
      ny = qy + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (!visit[nx][ny]) {
          if (A[nx][ny] == A[qx][qy]) {
            visit[nx][ny] = true;
            q.push(std::make_pair(nx, ny));
          }
        }
      }
    }
  }
}

void solve() {
  int res[2] = {0, 0};

  for (int t = 0; t < 2; t++) {
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        if (!visit[x][y]) {
          bfs(x, y);
          res[t]++;
        }
      }
    }
    applyG2R();
    memset(visit, false, sizeof(visit));
  }

  for (int i = 0; i < 2; i++) {
    std::cout << res[i] << '\n';
  }
}

void initial() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> A[i][j];
    }
  }
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
