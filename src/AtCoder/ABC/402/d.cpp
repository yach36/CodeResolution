#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> mod(n, 0);
  ll ans = m * ll(m - 1) / 2;  // mC2

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    mod[(a + b) % n]++;
  }

  for (int i = 0; i < n; i++) {
    int x = mod[i];
    ans -= x * ll(x - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}
