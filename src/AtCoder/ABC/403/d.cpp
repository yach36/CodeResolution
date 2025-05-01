#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<int> a) {
  int n = a.size();
  vector dp(n + 1, vector<int>(2));
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = max(dp[i][1], dp[i][0]);
    dp[i + 1][1] = dp[i][0] + a[i];
  }
  int mx = max(dp[n][0], dp[n][1]);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum - mx;
}

int main() {
  int N, D;
  cin >> N >> D;

  const int M = 1'000'005;
  vector<int> cnt(M);

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  int ans = 0;

  if (D == 0) {  // 同じ数字の重複を削除する
    for (int i = 0; i < M; i++) {
      if (cnt[i] > 0) {
        ans += cnt[i] - 1;
      }
    }

    cout << ans << endl;
    return 0;
  }

  for (int si = 0; si < D; si++) {  // mod Dごとに処理をする
    vector<int> a;
    for (int i = si; i < M; i += D) {
      a.push_back(cnt[i]);
    }
    ans += solve(a);
  }

  cout << ans << endl;
  return 0;
}
