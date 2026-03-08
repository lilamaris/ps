#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#include <queue>

#define MAX 101

std::queue<int> Q;
int N, M, count = 0;
int G[MAX][MAX];
bool visited[MAX] = {
    0,
};

void bfs(int s) {
  Q.push(s);
  visited[s] = true;

  while (!Q.empty()) {
    s = Q.front();
    Q.pop();

    for (int i = 1; i <= N; i++) {
      if (G[s][i] == 1 && visited[i] == 0) {
        Q.push(i);
        visited[i] = true;
        count++;
      }
    }
  }
}

void solve() {
  std::cin >> N >> M;

  int s, d;
  for (int i = 0; i < M; i++) {
    std::cin >> s >> d;

    G[s][d] = 1;
    G[d][s] = 1;
  }

  bfs(1);

  std::cout << count << '\n';
}

int main() {
  IO;
  solve();
  return 0;
}
