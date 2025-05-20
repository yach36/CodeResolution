#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;

  ll x, ans = 1, up = pow(10, k) - 1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x <= ceil(up / ans)) {
      ans *= x;
    } else {
      ans = 1;
    }
  }

  cout << ans << endl;
  return 0;
}
