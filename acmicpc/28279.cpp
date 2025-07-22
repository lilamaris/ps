#include <iostream>
#define IO std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
#define SIZE 1000001

int arr[SIZE], f = 0, r = 0;
bool empty() { return f == r; }
int size() { return f > r ? SIZE - f - r : r - f; }
int status(bool zzz) {
  if (zzz)
    return size();
  else
    return empty();
}
void push(bool front, int v) {
  if (f == 0)
    f = SIZE - 1;
  if (r == SIZE - 1)
    r = 0;
  if (front)
    arr[f--] = v;
  else
    arr[r++] = v;
}
int top(bool front) {
  if (f == r)
    return -1;
  if (front)
    return arr[fZ];
  else
    return arr[r];
}
int pop(bool front) {
  if (f == r)
    return -1;
  if (front)
    return arr[f++];
  else
    return arr[r--];
}

void solve() {
  int n, c, v;

  std::cin >> n;

  for (; n--;) {
    std::cin >> c;

    switch ((c + 1) / 2) {
    case 1:
      std::cin >> v;
      push(c % 2, v);
      break;
    case 2:
      std::cout << pop(c % 2) << '\n';
      break;
    case 3:
      std::cout << status(c % 2) << '\n';
      break;
    case 4:
      std::cout << top(c % 2) << '\n';
      break;
    }
  }
}

int main() {
  solve();
  return 0;
}
