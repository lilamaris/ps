#include <cstring>
#include <iostream>

struct stack {
  int arr[10000];
  int cur;

  void init() { cur = -1; };
  void push(int v) { arr[++cur] = v; }

  int pop() { return top(true); }

  int size() { return cur + 1; }

  bool empty() { return cur == -1; }

  int top(bool isPop = false) {
    if (empty())
      return -1;
    else {
      int v = arr[cur];
      cur -= isPop ? 1 : 0;
      return v;
    }
  }
};

stack st;

void solve() {
  char c[6];
  int v;

  std::cin >> c;
  if (strcmp(c, "push") == 0) {
    std::cin >> v;
    st.push(v);
  }
  if (strcmp(c, "pop") == 0)
    std::cout << st.pop() << '\n';
  if (strcmp(c, "size") == 0)
    std::cout << st.size() << '\n';
  if (strcmp(c, "empty") == 0)
    std::cout << st.empty() << '\n';
  if (strcmp(c, "top") == 0)
    std::cout << st.top() << '\n';
}

int main() {
  int n, v;

  std::cin >> n;
  st.init();

  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
