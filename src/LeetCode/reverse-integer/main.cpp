#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    if (x == 0) {
      return 0;
    }

    bool is_negative = x < 0;
    unsigned int y = is_negative ? (-1u) * x : x;
    long ans = 0, length = int(log10(y)) + 1;

    for (int i = 0; y > 0; i++) {
      int c = y % 10;
      ans += c * pow(10, length - i - 1);
      y /= 10;
    }

    bool of_plus = !is_negative && ans > pow(2, 31) - 1;
    bool of_negative = is_negative && ans > pow(2, 31);
    if (of_plus || of_negative) {
      return 0;
    }

    return is_negative ? (-1) * ans : ans;
  }
};