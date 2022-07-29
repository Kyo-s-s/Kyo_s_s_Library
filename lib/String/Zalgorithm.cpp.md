---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/Zalgorithm.md
    document_title: Z-algorithm
    links: []
  bundledCode: "#line 1 \"lib/String/Zalgorithm.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @brief Z-algorithm\n * @docs md/Zalgorithm.md\n\
    \ */\n\nvector<int> Zalgorithm(const string &S) {\n    vector<int> Z(S.size());\n\
    \    int i = 1, j = 0;\n    while(i < S.size()) {\n        while(i + j < (int)(S.size())\
    \ && S[j] == S[i + j]) j++;\n        Z[i] = j;\n\n        if(j == 0) {\n     \
    \       i++;\n            continue;\n        }\n\n        int k = 1;\n       \
    \ while(k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n}\n\ntemplate<class\
    \ T>\nvector<int> Zalgorithm(const vector<T> &S) {\n    vector<int> Z(S.size());\n\
    \    int i = 1, j = 0;\n    while(i < S.size()) {\n        while(i + j < (int)(S.size())\
    \ && S[j] == S[i + j]) j++;\n        Z[i] = j;\n\n        if(j == 0) {\n     \
    \       i++;\n            continue;\n        }\n\n        int k = 1;\n       \
    \ while(k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n}\n\nbool\
    \ is_SinT(string &S, string &T) {\n    string tmp = S + \"$\" + T;\n    vector<int>\
    \ Z = Zalgorithm(tmp);\n    bool ret = false;\n    for(int i = 1; i < (int)(Z.size());\
    \ i++) {\n        if(Z[i] >= (int)(S.size())) ret = true;\n    }\n    return ret;\n\
    }\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief Z-algorithm\n\
    \ * @docs md/Zalgorithm.md\n */\n\nvector<int> Zalgorithm(const string &S) {\n\
    \    vector<int> Z(S.size());\n    int i = 1, j = 0;\n    while(i < S.size())\
    \ {\n        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;\n       \
    \ Z[i] = j;\n\n        if(j == 0) {\n            i++;\n            continue;\n\
    \        }\n\n        int k = 1;\n        while(k < j && k + Z[k] < j) {\n   \
    \         Z[i + k] = Z[k];\n            k++;\n        }\n        i += k;\n   \
    \     j -= k;\n    }\n    return Z;\n}\n\ntemplate<class T>\nvector<int> Zalgorithm(const\
    \ vector<T> &S) {\n    vector<int> Z(S.size());\n    int i = 1, j = 0;\n    while(i\
    \ < S.size()) {\n        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;\n\
    \        Z[i] = j;\n\n        if(j == 0) {\n            i++;\n            continue;\n\
    \        }\n\n        int k = 1;\n        while(k < j && k + Z[k] < j) {\n   \
    \         Z[i + k] = Z[k];\n            k++;\n        }\n        i += k;\n   \
    \     j -= k;\n    }\n    return Z;\n}\n\nbool is_SinT(string &S, string &T) {\n\
    \    string tmp = S + \"$\" + T;\n    vector<int> Z = Zalgorithm(tmp);\n    bool\
    \ ret = false;\n    for(int i = 1; i < (int)(Z.size()); i++) {\n        if(Z[i]\
    \ >= (int)(S.size())) ret = true;\n    }\n    return ret;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/String/Zalgorithm.cpp
  requiredBy: []
  timestamp: '2022-02-05 15:52:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/String/Zalgorithm.cpp
layout: document
redirect_from:
- /library/lib/String/Zalgorithm.cpp
- /library/lib/String/Zalgorithm.cpp.html
title: Z-algorithm
---
# Zalgorithm

https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/String/Zalgorithm.cpp

Z-algorithm

```C++
(1) vector<int> Zalgorithm(string S)
(2) vector<int> Zalgorithm(vector<T> S)
```

入力の長さを$n$として, 長さ$n$の配列を返す. $i$番目の要素は`s[0..n)`と`s[i..n)`の最長共通接頭辞.

###### 計算量

- $O(|S|)$



```C++
bool is_SinT(string S, string T)
```

文字列$T$に文字列$S$が含まれるか, を返す. 文字列に\$が含まれる場合は壊れる. 適当に書き換えること.

###### 計算量

- $O(|S|+|T|)$

