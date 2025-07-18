#include <iostream>

using namespace std;

void solve() {
  int n, t = 0, avg, arr[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 5; i++) {
    cin >> n;
    arr[i] = n;
    t += n;
  }
  avg = t / 5;

  for (int i = 0; i < 5 - 1; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (arr[i] > arr[j]) {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
  cout << avg << endl;
  cout << arr[2] << endl;
}

int main() {
  solve();
  return 0;
}
