#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> all(N + 1);
  map<int, set<int>> auth;

  for (int i = 0; i < Q; i++) {
    int n, x, y;
    cin >> n;
    switch (n) {
      case 1:
        cin >> x >> y;
        auth[x].insert(y);
        break;
      case 2:
        cin >> x;
        all[x] = true;
        break;
      case 3:
        cin >> x >> y;
        if (all[x] || auth[x].count(y)) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
        break;
    }
  }
}
