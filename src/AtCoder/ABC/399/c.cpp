#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &g, int x, vector<bool> &seen) {
  seen[x] = true;

  for (int y : g[x]) {
    if (seen[y]) {
      continue;
    }
    dfs(g, y, seen);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int n_tree = 0;  // 連結成分数を求める
  vector<bool> seen(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (seen[i]) {
      continue;
    }
    dfs(graph, i, seen);
    n_tree++;
  }

  cout << m - (n - n_tree) << endl;
  return 0;
}
