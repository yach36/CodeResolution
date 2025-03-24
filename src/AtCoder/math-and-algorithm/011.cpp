#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v;
  v.push_back(2);
  cout << 2;

  for (int i = 3; i <= N; i++) {
    bool should_print = true;
    for (auto n : v) {
      if (i % n == 0) {
        should_print = false;
        break;
      }
    }

    if (should_print) {
      v.push_back(i);
      cout << " " << i;
    }
  }

  cout << endl;
}
