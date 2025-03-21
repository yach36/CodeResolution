#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  // 左から・右からi番目にぞれぞれ区切り線を設けたときの種類数を数える
  vector<int> numl(N), numr(N);
  {
    set<int> st;
    for (int i = 1; i < N; i++) {
      st.insert(A.at(i - 1));
      numl.at(i) = st.size();
    }
  }
  {
    set<int> st;
    for (int i = N - 1; i >= 0; i--) {
      st.insert(A.at(i));
      numr.at(i) = st.size();
    }
  }

  int ans = 0;
  for (int i = 1; i < N; i++) {
    ans = max(ans, numl.at(i) + numr.at(i));
  }

  cout << ans << endl;
}
