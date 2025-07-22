#include <iostream>
#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

int arr[1000], t = 0;

void push(int n) { arr[t++] = n; }
int pop() { return t > 0 ? arr[--t] : -1; }
int top() { return t > 0 ? arr[t - 1] : -1; }

void solve() {
  int n, m, a = 1;

  std::cin >> n;
  for (; n--;) {
    std::cin >> m;
    while (top() == a) {
      pop();
      a++;
    }

    if (m == a) {
      a++;
    } else {
      push(m);
    }
  }

  for (; t;) {
    if (pop() != a) {
      std::cout << "Sad";
      return;
    } else {
      a++;
    }
  }

  std::cout << "Nice";
}

int main() {
  solve();
  return 0;
}
