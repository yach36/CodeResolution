#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  long ans = 1;
  for (int i = N; i > 0; i--) {
    ans *= i;
  }

  cout << ans << endl;
}
