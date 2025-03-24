#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  // 先頭がiであること
  // 末尾がoであること
  // それ以外が隣り合っていないこと

  int ans = 0;
  if (S.at(0) != 'i') {
    ans++;
  }

  for (int i = 1; i < S.length(); i++) {
    if (S.at(i - 1) == S.at(i)) {
      ans++;
    }
  }

  if (S.at(S.length() - 1) != 'o') {
    ans++;
  }

  cout << ans << endl;
}
