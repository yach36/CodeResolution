### URL

https://leetcode.com/problems/string-to-integer-atoi/description/

### 方針

```cpp
// whitespaceは無視
// -あるいは+が最初に来る。来なければ+とみなす。
// 最初の0は無視して、数値でなければ終了
// [-2^31, 2^31-1]の範囲に収める。小さすぎる場合は-2^31,
// 大きすぎる場合は2^31-1として出力する
```

### Solutions

https://leetcode.com/problems/string-to-integer-atoi/solutions/6607615/topic/?source=submission-ac
