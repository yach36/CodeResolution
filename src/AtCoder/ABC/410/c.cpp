#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;

  map<int, int> modify;
  ll rotate = 0;

  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int p, x;
      cin >> p >> x;
      int op = p + rotate <= N ? p + rotate : (p + rotate) % N;
      modify[op] = x;
    } else if (type == 2) {
      int p;
      cin >> p;
      int op = p + rotate <= N ? p + rotate : (p + rotate) % N;
      if (modify.count(op)) {
        cout << modify[op] << endl;
      } else {
        cout << op << endl;
      }
    } else {
      ll k;
      cin >> k;
      rotate = (rotate + k) % N;
    }
  }
}
