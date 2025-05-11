## memo

### D

`E` から BFS で探索する

`.` を来た道に向けて矢印を指すように上書きする

↓DFS で解いちゃったときのコード

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<char>>;

void dfs(pair<int, int> p, Graph &g, vector<vector<bool>> &visited,
         char arrow = 'E') {
  int i, j;
  tie(i, j) = p;

  if (visited[i][j]) return;
  cout << i << " " << j << " " << g[i][j] << endl;

  visited[i][j] = true;

  if (g[i][j] == '#') return;

  g[i][j] = arrow;

  dfs(pair(i - 1, j), g, visited, 'v');  // up
  dfs(pair(i + 1, j), g, visited, '^');  // down
  dfs(pair(i, j + 1), g, visited, '<');  // right
  dfs(pair(i, j - 1), g, visited, '>');  // left
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool>> visited(1005, vector<bool>(1005));
  Graph s(1005, vector<char>(1005));
  for (int i = 0; i <= h; i++) {
    s[i][0] = s[i][w + 1] = '#';
  }
  for (int j = 0; j <= w; j++) {
    s[0][j] = s[h + 1][j] = '#';
  }

  pair<int, int> start;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'E') start = pair(i, j);
    }
  }

  dfs(start, s, visited);

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << s[i][j];
    }
    cout << "\n";
  }
}
```
