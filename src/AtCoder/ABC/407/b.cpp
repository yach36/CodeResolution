#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  double cnt = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i + j >= x || abs(i - j) >= y) cnt++;
    }
  }

  cout << fixed << setprecision(10);
  cout << cnt / 36 << endl;
}
