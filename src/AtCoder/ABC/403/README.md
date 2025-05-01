## memo

### D

- 解説を見た後のまとめ

mod D で分類した後、各グループで動的計画法(dp)を適用する
行は true/false, 列は各要素を表す
(例) A=[3 1 4 1 5], D=2 のとき
mod 2=0 => [4]
mod 2=1 => [3 1 1 5]

dp を適用して残す要素が最大となる選び方(<=>削除する最小の要素数)を求める

|       | 1   | 3   | 5   |
| ----- | --- | --- | --- |
| true  | 2   | 1   | 3   |
| false | 0   | 2   | 2   |

※true が連続で続いてはいけないことに注意

```cpp
dp[i][true] = dp[i-D][false] + cnt(i)
dp[i][false] = max(dp[i-D][true], dp[i-D][false])
```

- first impression

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // 前提：x>=0, y>=0
  // x-y=2となるような(x,y)のペアを作る
  // x,yのうち少ないほうの数を数える
  // (例) 1が2個, 3が1個のときは1
  //   これをすべてのペアに関して数えたものが回答となる

  int N, D;
  cin >> N >> D;

  set<pair<int, int>> pairs;  // (n+D,n) or (n,n-D)
  map<int, int> cnt;          // {<number>: <count>}
  set<int> counted;           // すでにansに加算したnumber
  int ans = 0;

  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    cnt[n]++;
    pairs.insert(n + D, n);
    if (n >= D) {
      pairs.insert(n, n - D);
    }
  }
}

// 思考2
// グラフとして(n-D)=(n)=(n+D)みたいにつなげて最小のノードを取り除けばよい？
```
