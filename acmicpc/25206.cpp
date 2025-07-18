#include <iostream>

using namespace std;

void solve() {
  string _, g;
  float ss, s, tot = 0, totsc = 0;
  char c = '+';

  for (int i = 0; i < 20; i++) {
    cin >> _ >> s >> g;
    if (g == "P")
      continue;
    ss = 69 - g[0];
    if (ss < 0)
      ss = 0;
    if (g.length() == 2 && g.at(1) == c)
      ss += 0.5;
    tot += ss * s;
    totsc += s;
  }
  cout << tot / totsc << endl;
}

int main() {
  solve();
  return 0;
}
