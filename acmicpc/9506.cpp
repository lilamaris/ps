#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, a;
  vector<int> arr;

  while (true) {
    cin >> n;
    if (n == -1)
      return;
    a = 0;
    arr = {};
    for (int i = 1; i < n; i++) {
      if (n % i == 0) {
        arr.push_back(i);
        a += i;
      }
    }
    cout << n;
    if (n != a)
      cout << " is NOT perfect." << endl;
    else {
      cout << " = " << arr[0];
      for (int i = 1; i < arr.size(); i++)
        cout << " + " << arr[i];
      cout << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
