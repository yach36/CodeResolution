#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    vector<queue<char>> A(1000);

    int col = 0;
    {
      int i = 0;
      bool finished = false;
      while (true) {
        // numRows文字埋めるモード
        for (int j = 0; j < numRows; j++) {
          A.at(col).push(s.at(i));

          i++;
          if (i >= int(s.size())) {
            finished = true;
            break;
          }
        }
        if (finished) {
          break;
        }
        col++;

        // 斜め方向に文字を配置するモード
        for (int j = numRows - 2; j > 0; j--) {
          for (int k = 0; k < numRows; k++) {
            if (k == j) {
              A.at(col).push(s.at(i));
            } else {
              A.at(col).push('#');
            }
          }

          i++;
          if (i >= int(s.size())) {
            finished = true;
            break;
          }
          col++;
        }
        if (finished) {
          break;
        }
      }
    }

    // 出力
    string ans;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j <= col; j++) {
        char front = A.at(j).front();
        if (front != '#') {
          ans.push_back(front);
        }

        if (!A.at(j).empty()) {
          A.at(j).pop();
        }
      }
    }

    return ans;
  }
};

int main() {
  auto sl = new Solution();
  string s;
  int n;
  cin >> s >> n;
  string ans = sl->convert(s, n);
  cout << ans << endl;
}
