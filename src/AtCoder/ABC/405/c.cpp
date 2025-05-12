#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    ans += sum * a[i];
    sum += a[i];
  }

  cout << ans << endl;
}
