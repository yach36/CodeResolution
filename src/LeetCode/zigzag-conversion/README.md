### URL

https://leetcode.com/problems/zigzag-conversion/description/

### 方針

```txt
s="PAYPALISHIRING", numRows=n=4 のとき
(変換前の位置)=>(変換後の位置)
0=>0, 6(=2*(n-1))=>1, 12(=2*(2*(n-1)))=>2
1=>3(=1+(P,I,N)=((s.length-1)/(2*(n-1))+1)

PAYPAL, ISHIRI, NG
2\*(n-1)=6 文字ごとにグループ分け
グループごとに配列に格納する。
ex) A[0][0]="P", A[0][1]="AL", A[0][2]="YA", A[0][3]="P"
グループごとに巡回し、2 番目のインデックスのタイミングで ans に push する。
```

### main 関数

```cpp
int main() {
  Solution solution;
  string s = "PAYPALISHIRING";
  int numRows = 3;
  cout << solution.convert(s, numRows) << endl;
}
```
