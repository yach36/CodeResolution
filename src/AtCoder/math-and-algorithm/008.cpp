#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (S < i + j) {
        break;
      }
      ans++;
    }
  }

  cout << ans << endl;
}
