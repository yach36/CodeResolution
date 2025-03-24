#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= int(s.size())) {
      return s;
    }

    int unit = 2 * (numRows - 1);
    int numGroups = (int(s.size()) - 1) / unit + 1;
    vector<queue<string>> A(numGroups);

    for (int i = 0; i < int(s.size()); i += unit) {
      int group = i / unit;
      A.at(group).push({s.at(i)});
      if (i + 1 >= int(s.size())) {
        break;
      }

      for (int l = i + 1, r = (group + 1) * unit - 1;
           r - l >= 0 && l < int(s.size()); l++, r--) {
        if (r == l || r >= int(s.size())) {
          A.at(group).push({s.at(l)});
        } else {
          A.at(group).push({s.at(l), s.at(r)});
        }
      }
    };

    string ans = "";
    const int size = int(A.at(0).size());
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < int(A.size()); j++) {
        if (!A.at(j).empty()) {
          ans += A.at(j).front();
          A.at(j).pop();
        }
      }
    }
    return ans;
  }
};
