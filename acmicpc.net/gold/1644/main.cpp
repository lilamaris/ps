#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define IO std::cin.tie(NULL), std::ios_base::sync_with_stdio(false)

#define MAX 4000000

bool prime[MAX];
int N;
std::vector<int> A;

void initialPrime() {
  std::fill(prime, prime + MAX, true);
  prime[0] = false;
  prime[0] = false;

  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }

  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      A.push_back(i);
    }
  }
}

void solve() {
  std::cin >> N;

  initialPrime();

  int l = 0, r = 0, count = 0, current = 0;

  while (true) {
    if (current >= N) {
      if (current == N)
        count++;
      current -= A[l++];
    } else {
      if (r == A.size())
        break;
      current += A[r++];
    }
  }

  std::cout << count;
}

int main() {
  IO;
  solve();
  return 0;
}
