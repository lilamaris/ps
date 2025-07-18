#include <iostream>
#include <stack>

using namespace std;

void solve() {
  int n, b;
  cin >> n >> b;
  if (n == 0) {
    cout << 0 << endl;
    return;
  }

  if (b == 10) {
    cout << n << endl;
    return;
  }
  stack<char> res;
  int m;

  while (n > 0) {
    m = n % b;
    res.push(m < 10 ? m + '0' : (m - 10) + 'A');
    n /= b;
  }

  while (!res.empty()) {
    cout << res.top();
    res.pop();
  }
}

int main() {
  solve();
  return 0;
}
