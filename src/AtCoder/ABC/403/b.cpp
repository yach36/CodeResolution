#include <bits/stdc++.h>
using namespace std;

int main() {
  string T, U;
  cin >> T >> U;

  for (int i = 0; i <= int(T.size() - U.size()); i++) {  // iは開始位置
    bool matched = true;
    for (int j = i, k = 0; k < int(U.size()); j++, k++) {
      if (T[j] == '?') {
        continue;
      };

      if (T[j] != U[k]) {
        matched = false;
        break;
      }
    }

    if (matched) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
