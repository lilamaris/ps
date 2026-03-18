#include <algorithm>
#include <iostream>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 1001

int A[MAX], B[MAX];
std::vector<int> PA, PB;
int T, N, M;

void solve() {
  std::cin >> T >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::cin >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> B[i];
  }

  for (int i = 0; i < N; i++) {
    PA.push_back(A[i]);
    for (int j = i + 1; j < N; j++) {
      PA.push_back(A[j] + PA.back());
    }
  }

  for (int i = 0; i < M; i++) {
    PB.push_back(B[i]);
    for (int j = i + 1; j < M; j++) {
      PB.push_back(B[j] + PB.back());
    }
  }

  std::sort(PA.begin(), PA.end());
  std::sort(PB.begin(), PB.end());

  for (auto Ae : PA) {
    std::cout << Ae << ' ';
  }
  std::cout << '\n';

  for (auto Be : PB) {
    std::cout << Be << ' ';
  }
  std::cout << '\n';

  long long count = 0;

  for (auto Ae : PA) {
    int target = T - Ae;

    int lo = std::lower_bound(PB.begin(), PB.end(), target) - PB.begin();

    int hi = std::upper_bound(PB.begin(), PB.end(), target) - PB.begin();

    count += (hi - lo);
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
