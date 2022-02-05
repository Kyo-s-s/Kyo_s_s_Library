# Zalgorithm

Z-algorithm

```C++
(1) vector<int> Zalgorithm(string S)
(2) vector<int> Zalgorithm(vector<T> S)
```

入力の長さを$n$として, 長さ$n$の配列を返す. $i$番目の要素は`s[0..n)`と`s[i..n)`の最長共通接頭辞.

###### 計算量

- $O(|S|)$



```C++
bool is_SinT(strin S, string T)
```

文字列$T$に文字列$S$が含まれるか, を返す. 文字列に\$が含まれる場合は壊れる. 適当に書き換えること.

###### 計算量

- $O(|S|+|T|)$

