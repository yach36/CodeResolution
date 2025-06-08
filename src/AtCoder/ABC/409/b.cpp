#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  for (int i = n; i >= 0; --i) {
    int cnt = 0;
    for (auto x : a) {
      if (x >= i) cnt++;
    }
    if (cnt >= i) {
      cout << i << endl;
      return 0;
    }
  }
}
