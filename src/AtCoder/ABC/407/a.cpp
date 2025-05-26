#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int x = a / b;
  int y = b * x, z = b * (x + 1);

  if (a - y < z - a) {
    cout << x << endl;
  } else {
    cout << x + 1 << endl;
  }
  return 0;
}
