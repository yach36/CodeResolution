#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(p.at(i));
  }

  map<int, int> rank;  // (値, 順位)
  {
    int r = 1;
    while (!q.empty()) {
      int tp = q.top();
      if (!rank.count(tp)) {
        rank[tp] = r;
      }
      r++;
      q.pop();
    }
  }

  for (int i = 0; i < n; i++) {
    cout << rank.at(p.at(i)) << endl;
  }

  return 0;
}
