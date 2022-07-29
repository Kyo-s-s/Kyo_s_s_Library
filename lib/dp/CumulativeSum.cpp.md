---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/CumulativeSum.md
    document_title: "Cumulative Sum (\u4E00\u6B21\u5143\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 1 \"lib/dp/CumulativeSum.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/**\n * @brief Cumulative Sum (\u4E00\u6B21\u5143\u7D2F\u7A4D\
    \u548C)\n * @docs md/CumulativeSum.md\n */\n\ntemplate<class T> struct CumulativeSum{\n\
    \  public:\n    CumulativeSum(int n) : CumulativeSum(std::vector<T> (n)) {}\n\
    \    CumulativeSum(const std::vector<T> &v) : _n(v.size()){\n        data = std::vector<T>\
    \ (_n + 1);\n        for(int i = 0; i < _n; i++){\n            data[i + 1] = v[i];\n\
    \        }\n    }\n\n    void update(int p, const T &x) {\n        assert(0 <=\
    \ p && p < _n);\n        data[p + 1] = x;\n    }\n\n    void add(int p, const\
    \ T &x){\n        assert(0 <= p && p < _n);\n        data[p + 1] += x;\n    }\n\
    \n    void build() {\n        for(int i = 1; i < data.size(); i++){\n        \
    \    data[i] += data[i - 1];\n        }\n    }\n\n    T sum(int r) {\n       \
    \ assert(0 <= r && r <= _n);\n        return data[r];\n    }\n\n    T sum(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= _n);\n        return sum(r)\
    \ - sum(l);\n    }\n\n  private:\n    int _n;\n    std::vector<T> data;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief Cumulative\
    \ Sum (\u4E00\u6B21\u5143\u7D2F\u7A4D\u548C)\n * @docs md/CumulativeSum.md\n */\n\
    \ntemplate<class T> struct CumulativeSum{\n  public:\n    CumulativeSum(int n)\
    \ : CumulativeSum(std::vector<T> (n)) {}\n    CumulativeSum(const std::vector<T>\
    \ &v) : _n(v.size()){\n        data = std::vector<T> (_n + 1);\n        for(int\
    \ i = 0; i < _n; i++){\n            data[i + 1] = v[i];\n        }\n    }\n\n\
    \    void update(int p, const T &x) {\n        assert(0 <= p && p < _n);\n   \
    \     data[p + 1] = x;\n    }\n\n    void add(int p, const T &x){\n        assert(0\
    \ <= p && p < _n);\n        data[p + 1] += x;\n    }\n\n    void build() {\n \
    \       for(int i = 1; i < data.size(); i++){\n            data[i] += data[i -\
    \ 1];\n        }\n    }\n\n    T sum(int r) {\n        assert(0 <= r && r <= _n);\n\
    \        return data[r];\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l < r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<T> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2022-02-04 01:25:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/CumulativeSum.cpp
layout: document
redirect_from:
- /library/lib/dp/CumulativeSum.cpp
- /library/lib/dp/CumulativeSum.cpp.html
title: "Cumulative Sum (\u4E00\u6B21\u5143\u7D2F\u7A4D\u548C)"
---
# Cumulative Sum

https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/dp/CumulativeSum.cpp

1次元累積和

## コンストラクタ

```C++
(1) CumuativeSum<T> cs(int n)
(2) CumuativeSum cs(vector<T> v)
```

- (1): 長さ`n+1`, 型`T`の数列を作る. 値はすべて初期値.
- (2): 長さ`n = v.size() + 1`, 型`T`の数列を作る. vの内容が初期値となる.

###### 計算量

- $O(n)$

## update

```C++
void cs.update(int p, T x)
```

`a[p]`の値を`x`に更新する.

###### 制約

- $0 \leq p < n$

###### 計算量

- $O(1)$

## add

```C++
void cs.add(int p, T x)
```

`a[p]`に`x`を加算する. 

###### 制約

- $0 \leq p < n$

###### 計算量

- $O(1)$

## build

```C++
void cs.build()
```

累積和をとる. 以後, `sum`が使えるようになる. 

###### 計算量

- $O(n)$

## sum

```C++
(1) T cs.sum(int r)
(2) T cs.sum(int l, int r)
```

- (1): 区間$[0, r)$の和を返す.
- (2): 区間$[l, r)$の和を返す.

###### 制約

- (1): $0 \leq r \leq n$
- (2): $0 \leq l < r \leq n$
###### 計算量

- $O(1)$

