#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // 食材視点で現時点で克服できていないメニューを格納しておく。
  vector<vector<int>> menus(n);
  // メニュー視点で現時点で克服できていない食材数を格納しておく。0になるとansが増える。
  vector<int> cnt(m);
  int ans = 0;

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    cnt[i] = k;

    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      a--;
      menus[a].push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    b--;
    for (auto x : menus[b]) {
      cnt[x]--;
      if (cnt[x] == 0) {
        ans++;
      }
    }

    cout << ans << '\n';  // 出力数が多すぎるとendlは遅いらしい
  }

  return 0;
}
