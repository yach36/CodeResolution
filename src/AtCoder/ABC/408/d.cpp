#include <bits/stdc++.h>
using namespace std;

vector<int> match_successive_one(string s) {
  int cnt = 0;
  vector<int> ans;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '1') {
      cnt++;
      if (i == int(s.size() - 1)) {
        if (cnt > 0) ans.push_back(cnt);
      } else if (s[i + 1] == '0') {
        ans.push_back(cnt);
        cnt = 0;
      }
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    string s;
    cin >> n >> s;

    auto v = match_successive_one(s);
    for (int i : v) {
      cout << "i: " << i << endl;
    }
    if (v.size() <= 1) {
      cout << 0 << endl;
    } else {
      int sum = 0, mx = 0;
      for (int i : v) {
        sum += i;
        mx = max(mx, i);
      }
      cout << sum - mx << endl;
    }
  }
}
