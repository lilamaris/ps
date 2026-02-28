#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1000

int MY, MX;
int A[MAX][MAX];
std::queue<std::pair<int, int>> q;
bool visit[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
  int qx, qy, cx, cy;
  while (!q.empty()) {
    qx = q.front().first;
    qy = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      cx = qx + dx[i];
      cy = qy + dy[i];

      if (0 <= cx && cx < MX && 0 <= cy && cy < MY) {
        if (visit[cy][cx])
          continue;

        visit[cy][cx] = true;
        q.push(std::make_pair(cx, cy));
        A[cy][cx] = A[qy][qx] + 1;
      }
    }
  }
}

void solve() {
  bfs();

  int max = 0;
  for (int y = 0; y < MY; y++) {
    for (int x = 0; x < MX; x++) {
      if (A[y][x] == 0) {
        std::cout << -1;
        return;
      }
      max = std::max(max, A[y][x]);
    }
  }

  std::cout << max - 1;
}

void initial() {
  std::cin >> MX >> MY;

  for (int y = 0; y < MY; y++) {
    for (int x = 0; x < MX; x++) {
      std::cin >> A[y][x];
      if (A[y][x] == 1) {
        q.push(std::make_pair(x, y));
        visit[y][x] = true;
      }
      if (A[y][x] == -1) {
        visit[y][x] = true;
      }
    }
  }
}

int main() {
  IO;
  initial();
  solve();
  return 0;
}
