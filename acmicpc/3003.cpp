#include <iostream>

using namespace std;

void solve() {
  int arr[6] = {1, 1, 2, 2, 2, 8};
  int a;
  for (int i = 0; i < 6; i++) {
    cin >> a;
    cout << arr[i] - a << " ";
  }
}

int main() {
  solve();
  return 0;
}
