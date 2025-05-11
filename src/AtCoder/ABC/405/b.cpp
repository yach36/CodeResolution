#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> cnt(n + 1);
  stack<int> stk;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    stk.push(a);
    cnt[a]++;
  }

  for (int i = 1; i <= m; i++) {
    if (!cnt[i]) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
  while (!stk.empty()) {
    ans++;
    int a = stk.top();
    stk.pop();
    cnt[a]--;
    if (!cnt[a]) break;
  }

  cout << ans << endl;
}
