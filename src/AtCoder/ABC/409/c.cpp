#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // Lが3の倍数の場合のみ正三角形ができる
  // L/3(グループ)に分けることができる
  // グループごとに組み合わせを計算し、各グループの総和が求める値となる

  int N, L;
  cin >> N >> L;
  if (L % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> a(L), d(N);
  for (int i = 1; i < N; i++) cin >> d[i];
  for (int i = 1; i < N; i++) d[i] += d[i - 1];
  a[0]++;
  for (int i = 1; i < N; i++) {
    a[d[i] % L]++;
  }

  ll ans = 0, dd = L / 3;
  for (int i = 0; i < dd; i++) {
    ans += a[dd * 0 + i] * a[dd * 1 + i] * a[dd * 2 + i];
  }
  cout << ans << endl;
}
