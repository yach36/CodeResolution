#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> s;

  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) s.insert(a[i]);

  cout << s.size() << endl;
  for (int i = 0; i < n; i++) {
    if (s.count(a[i])) {
      cout << a[i];
      s.erase(a[i]);

      if (s.empty())
        cout << endl;
      else
        cout << " ";
    }
  }
}
