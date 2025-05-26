#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 0, sub = 0;
  reverse(s.begin(), s.end());
  for (char c : s) {
    // 文字列の末尾から走査して、引き算をして空文字になるようにする
    int n = c - '0';

    int cur = n - sub >= 0 ? n - sub : 10 + n - sub;
    ans += cur + 1;

    sub = (sub + cur) % 10;
  }

  cout << ans << endl;
}
