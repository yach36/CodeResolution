### 回答履歴

#### c 問題

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<set<int>> A(m, set<int>());
  deque<int> B;               // 食べられない食材
  vector<bool> de(m, false);  // 克服したかどうかをメモ

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      A[i].insert(x);
    }
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    B.push_back(x);
  }

  //   毎日1個克服する。(食材の種類数)=(克服にかける日数)
  //   m個の料理のうち、いくつ食べられるかを日ごとに出力する
  {
    int cnt = 0;
    for (int i = 0; i < n; i++) {  // i日目
      B.pop_front();

      for (int j = 0; j < m; j++) {  // m個の料理分カウント
        if (de[j]) {                 // 克服済みの場合はスキップ
          continue;
        }

        bool can_eat = true;
        for (int x : B) {  // 食べられない食材が料理にあるかを調べる
          if (A[j].count(x)) {
            can_eat = false;
            break;
          }
        }

        if (can_eat) {
          de[j] = true;
          cnt++;
        }
      }

      cout << cnt << endl;
    }
  }

  return 0;
}

```
