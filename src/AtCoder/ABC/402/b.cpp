#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  queue<int> que;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (a == 1) {
      int x;
      cin >> x;
      que.push(x);
    } else {
      cout << que.front() << endl;
      que.pop();
    }
  }

  return 0;
}
