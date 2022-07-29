---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/Enumeration.md
    document_title: "Enumeration (\u7D44\u307F\u5408\u308F\u305B)"
    links: []
  bundledCode: "#line 1 \"lib/math/Enumeration.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/**\n * @brief Enumeration (\u7D44\u307F\u5408\u308F\u305B\
    )\n * @docs md/Enumeration.md\n */\n\ntemplate<class T> struct Enumeration{\n\
    \  public:\n    Enumeration(int sz = 0) { update(sz); }\n\n    T fact(int k) {\n\
    \        update(k);\n        return _fact[k];\n    }\n\n    T finv(int k) {\n\
    \        update(k);\n        return _finv[k];\n    }\n\n    T inv(int k) {\n \
    \       update(k);\n        return _inv[k];\n    }\n\n    T nPk(int n, int k)\
    \ {\n        if(k < 0 || n < k) return 0;\n        return fact(n) * finv(n - k);\n\
    \    }\n\n    T nCk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n  \
    \      return fact(n) * finv(k) * finv(n - k);\n    }\n\n    T nHk(int n, int\
    \ k) {\n        if(n < 0 || k < 0) return 0;\n        if(n == 0) return 1;\n \
    \       else return nCk(n + k - 1, k);\n    }\n\n  private:\n    vector<T> _fact,\
    \ _finv, _inv;\n\n    void update(int sz) {\n        if(_fact.size() < sz + 1){\n\
    \            int pre_sz = max(1, (int)_fact.size());\n            _fact.resize(sz\
    \ + 1, T(1));\n            _finv.resize(sz + 1, T(1));\n            _inv.resize(sz\
    \ + 1, T(1));\n            for(int i = pre_sz; i <= (int)sz; i++) {\n        \
    \        _fact[i] = _fact[i - 1] * T(i);\n            }\n            _finv[sz]\
    \ = T(1) / _fact[sz];\n            for(int i = (int)sz - 1; i >= pre_sz; i--)\
    \ {\n                _finv[i] = _finv[i + 1] * T(i + 1);\n            }\n    \
    \        for(int i = pre_sz; i <= (int)sz; i++) {\n                _inv[i] = _finv[i]\
    \ * _fact[i - 1];\n            }\n        }\n    }\n\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief Enumeration\
    \ (\u7D44\u307F\u5408\u308F\u305B)\n * @docs md/Enumeration.md\n */\n\ntemplate<class\
    \ T> struct Enumeration{\n  public:\n    Enumeration(int sz = 0) { update(sz);\
    \ }\n\n    T fact(int k) {\n        update(k);\n        return _fact[k];\n   \
    \ }\n\n    T finv(int k) {\n        update(k);\n        return _finv[k];\n   \
    \ }\n\n    T inv(int k) {\n        update(k);\n        return _inv[k];\n    }\n\
    \n    T nPk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n        return\
    \ fact(n) * finv(n - k);\n    }\n\n    T nCk(int n, int k) {\n        if(k < 0\
    \ || n < k) return 0;\n        return fact(n) * finv(k) * finv(n - k);\n    }\n\
    \n    T nHk(int n, int k) {\n        if(n < 0 || k < 0) return 0;\n        if(n\
    \ == 0) return 1;\n        else return nCk(n + k - 1, k);\n    }\n\n  private:\n\
    \    vector<T> _fact, _finv, _inv;\n\n    void update(int sz) {\n        if(_fact.size()\
    \ < sz + 1){\n            int pre_sz = max(1, (int)_fact.size());\n          \
    \  _fact.resize(sz + 1, T(1));\n            _finv.resize(sz + 1, T(1));\n    \
    \        _inv.resize(sz + 1, T(1));\n            for(int i = pre_sz; i <= (int)sz;\
    \ i++) {\n                _fact[i] = _fact[i - 1] * T(i);\n            }\n   \
    \         _finv[sz] = T(1) / _fact[sz];\n            for(int i = (int)sz - 1;\
    \ i >= pre_sz; i--) {\n                _finv[i] = _finv[i + 1] * T(i + 1);\n \
    \           }\n            for(int i = pre_sz; i <= (int)sz; i++) {\n        \
    \        _inv[i] = _finv[i] * _fact[i - 1];\n            }\n        }\n    }\n\
    \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Enumeration.cpp
  requiredBy: []
  timestamp: '2022-02-04 19:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Enumeration.cpp
layout: document
redirect_from:
- /library/lib/math/Enumeration.cpp
- /library/lib/math/Enumeration.cpp.html
title: "Enumeration (\u7D44\u307F\u5408\u308F\u305B)"
---
# Enumeration

https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/math/Enumeration.cpp

組み合わせ

## コンストラクタ

```C++
Enumeration<T> enu
```

`fact`, `finv`, `inv`配列を作成. 

###### 計算量

- $O(1)$

## fact

```C++
enu.fact(int n)
```

$n!$を求める.

###### 計算量

- `update`されていない場合、`n`まで`update`を行う。
- それ以降は$O(1)$

## finv

```C++
enu.finv(int n)
```

$(n!)^{-1}$を求める.

###### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## inv

```C++
enu.inv(int n)
```

$n^{-1}$を求める.

###### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nPk

```C++
enu.nPk(int n, int k)
```



${}_nP_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

###### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nCk

```C++
enu.nCk(int n, int k)
```



${}_nC_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

###### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nHk

```C++
enu.nHk(int n, int k)
```



${}_nH_k$を求める. $k < 0$または$n < 0$の場合, $0$を返す.

###### 計算量

- `update`されていない場合, `n+k-1`まで`update`を行う.
- それ以降は$O(1)$