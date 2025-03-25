#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  // x-y=d
  for (ll d = 1; d * d * d < N; d++) {
    ll c = (N - d * d * d);
    if (c % (3 * d) != 0) {
      continue;
    }
    c /= 3 * d;
    ll y = (sqrt(d * d + 4 * c) - d) / 2;
    if (y * y + d * y - c == 0) {
      cout << y + d << " " << y << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
