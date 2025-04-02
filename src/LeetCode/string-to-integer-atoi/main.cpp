#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
 public:
  int myAtoi(string s) {
    string mode = "sign";  // 符号, 数字のどちらを受け入れるかを表す "sign" |
                           // "digit" | "digit-writing"
    bool finished = false;
    string ans = "";
    for (char c : s) {
      if (finished) {
        break;
      }

      if (this->check_whitespace(c, mode, finished, ans)) {
        continue;
      }

      if (this->check_sign(c, mode, finished, ans)) {
        continue;
      }

      if (this->check_digit(c, mode, finished, ans)) {
        continue;
      }

      this->check_no_digit(c, mode, finished, ans);
    }

    if (ans == "" || ans == "-") {
      return 0;
    }

    const int min = INT32_MIN;
    const int max = INT32_MAX;
    if (ans.size() > 11) {
      return ans.at(0) == '-' ? min : max;
    }

    ll numll = stoll(ans);
    if (numll < min) {
      return min;
    }
    if (numll > max) {
      return max;
    }

    return stoi(ans);
  }

  //   check_* 関数は各文字の条件に合致するとtrueを返す
 private:
  // ' 'のチェック
  bool check_whitespace(char c, string &mode, bool &finished, string &ans) {
    if (c != ' ') return false;

    if (mode == "sign") {
      return true;
    }
    finished = true;
    return true;
  }

  //  '+'と'-'のチェック
  bool check_sign(char c, string &mode, bool &finished, string &ans) {
    if (c != '+' && c != '-') return false;

    if (mode == "sign") {
      if (c == '-') ans += c;
      mode = "digit";
      return true;
    }

    finished = true;
    return true;
  }

  //   [0-9]のチェック
  bool check_digit(char c, string &mode, bool &finished, string &ans) {
    if (!isdigit(c)) return false;

    if (mode == "sign") {
      if (c == '0') {
        mode = "digit";
      } else {
        ans += c;
        mode = "digit-writing";
      }
    } else if (mode == "digit") {
      if (c != '0') {
        ans += c;
        mode = "digit-writing";
      }
    } else {
      ans += c;
    }

    return true;
  }

  //   [A-Za-z]のチェック
  bool check_no_digit(char c, string &mode, bool &finished, string &ans) {
    finished = true;
    return true;
  }
};