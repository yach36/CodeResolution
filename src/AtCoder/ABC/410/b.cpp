#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> box(N);
  for (int i = 0; i < Q; i++) {
    int x;
    cin >> x;

    if (x == 0) {
      int mj = -1, min = 105;
      for (int j = 0; j < N; j++) {
        if (box[j] < min) {
          mj = j;
          min = box[j];
        }
      }
      box[mj]++;
      cout << mj + 1 << " \n"[i + 1 == Q];
      continue;
    }

    box[x - 1]++;
    cout << x << " \n"[i + 1 == Q];
  }
}
