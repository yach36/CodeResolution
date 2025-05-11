#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<char>>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool>> visited(1005, vector<bool>(1005));
  Graph s(1005, vector<char>(1005));

  // ダミーの外壁を作成
  for (int i = 0; i <= h; i++) {
    s[i][0] = s[i][w + 1] = '#';
  }
  for (int j = 0; j <= w; j++) {
    s[0][j] = s[h + 1][j] = '#';
  }

  queue<pair<int, int>> start;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'E') start.push(pair(i, j));
    }
  }

  // BFS
  queue<pair<pair<int, int>, char>> que;
  while (!start.empty()) {
    auto p = start.front();
    start.pop();
    que.emplace(p, 'E');
  }
  while (!que.empty()) {
    auto p = que.front();
    que.pop();

    auto pos = p.first;
    int i, j;
    tie(i, j) = pos;
    if (visited[i][j]) continue;
    visited[i][j] = true;

    if (s[i][j] == '#') continue;

    char c = p.second;
    s[i][j] = c;

    que.emplace(pair(i - 1, j), 'v');  // up
    que.emplace(pair(i + 1, j), '^');  // down
    que.emplace(pair(i, j - 1), '>');  // left
    que.emplace(pair(i, j + 1), '<');  // right
  }

  // 出力
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << s[i][j];
    }
    cout << "\n";
  }
}
