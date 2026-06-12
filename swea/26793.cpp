#include <iostream>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 500000
int first[MAX];
int second[MAX];

int mex(int i, int j) {
  bool exists[3] = {
      false,
  };
  exists[i] = true;
  exists[j] = true;
  for (int i = 0; i < 3; i++) {
    if (!exists[i])
      return i;
  }
  return 0;
}

void solve() {
  int T, N;
  std::cin >> T;

  while (T--) {
    int count[3];

    std::cin >> N;

    std::fill(count, count + 3, 0);

    int *previous = first;
    int *current = second;

    for (int col = 0; col < N; col++) {
      int x;
      std::cin >> x;
      count[x]++;
      previous[col] = x;
    }

    for (int row = 1; row < N; row++) {
      int x;
      std::cin >> x;
      current[0] = x;
      count[x]++;

      for (int col = 1; col < N; col++) {
        int x = mex(current[col - 1], previous[col]);
        count[x]++;
        current[col] = x;
      }

      int *tmp = previous;
      previous = current;
      current = tmp;
    }

    for (int i = 0; i < 3; i++) {
      std::cout << count[i] << " ";
    }
    std::cout << '\n';
  }
}

int main() {
  IO;
  solve();
  return 0;
}
