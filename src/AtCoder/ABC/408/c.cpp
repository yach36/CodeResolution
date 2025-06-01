#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 2);

  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }

  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int ans = m;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, a[i]);
  }
  cout << ans << endl;
}
