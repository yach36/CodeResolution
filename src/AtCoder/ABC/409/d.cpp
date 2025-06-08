#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    string S;
    cin >> N >> S;

    bool shiftable = false, shifted = false;
    pair<int, char> p(0, S[0]);
    for (int i = 1; i < N; i++) {
      if (!shiftable) {
        if (S[i - 1] > S[i]) {
          p.first = i - 1;
          p.second = S[i - 1];
          shiftable = true;
        }
      } else {
        if (p.second < S[i]) {
          S.insert(S.begin() + i, p.second);
          S.erase(S.begin() + p.first);
          shifted = true;
          break;
        }
      }
    }
    if (shiftable && !shifted) {
      S.erase(S.begin() + p.first);
      S.push_back(p.second);
    }

    cout << S << endl;
  }
}