#include <iostream>

using namespace std;

void solve() {
  int v;
  bool arr[30];
  for (int i = 0; i < 30; i++) {
    arr[i] = false;
  }

  for (int i = 0; i < 30; i++) {
    cin >> v;
    arr[v - 1] = true;
  }

  for (int i = 0; i < 30; i++) {
    if (!arr[i])
      cout << i + 1 << endl;
  }
}

int main() {
  solve();
  return 0;
}
