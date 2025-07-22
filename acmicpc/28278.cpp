#include <iostream>
#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr)

int arr[1000000], t = 0;

void push(int v) {
  arr[t] = v;
  t++;
}
int size() { return t; }
bool empty() { return t == 0; }
int top() {
  if (empty())
    return -1;
  return arr[t - 1];
}
int pop() {
  if (empty())
    return -1;
  int v = top();
  t--;
  return v;
}

void solve() {
  int n, c, v;
  std::cin >> n;
  for (; n--;) {
    std::cin >> c;
    switch (c) {
    case 1:
      std::cin >> v;
      push(v);
      break;
    case 2:
      std::cout << pop() << '\n';
      break;
    case 3:
      std::cout << size() << '\n';
      break;
    case 4:
      std::cout << empty() << '\n';
      break;
    case 5:
      std::cout << top() << '\n';
    default:
      break;
    }
  }
}

int main() {
  IO;
  solve();
  return 0;
}
