#include <bits/stdc++.h>
using namespace std;

int main() {
  float X;
  cin >> X;

  int ans;
  if (X >= 38.0) {
    ans = 1;
  } else if (X >= 37.5) {
    ans = 2;
  } else {
    ans = 3;
  }

  cout << ans << endl;
}
