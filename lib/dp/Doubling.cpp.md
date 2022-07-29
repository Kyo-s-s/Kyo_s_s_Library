---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/dp/Doubling.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n\ntemplate <class S>\nstruct Doubling{\n  public:\n    Doubling(function<S(S,\
    \ S)> op, function<int(S)> idx, vector<S> v) : _op(op), _idx(idx) {\n        table.resize(62,\
    \ vector<S>(v.size()));\n        for(int i = 0; i < v.size(); i++) table[0][i]\
    \ = v[i];\n        for(int i = 0; i < 61; i++){\n            for(int j = 0; j\
    \ < v.size(); j++){\n                table[i+1][j] = _op(table[i][j], table[i][_idx(table[i][j])]);\n\
    \            }\n        }\n    }        \n    \n    S query(S s, long long n){\n\
    \        for(int i = 0; i < 62; i++) if((n >> i) & 1){\n            s = _op(s,\
    \ table[i][_idx(s)]);\n        }\n        return s;\n    }\n    \n  private:\n\
    \    function<S(S, S)> _op;\n    function<int(S)> _idx;\n    vector<vector<S>>\
    \ table;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n\ntemplate <class S>\n\
    struct Doubling{\n  public:\n    Doubling(function<S(S, S)> op, function<int(S)>\
    \ idx, vector<S> v) : _op(op), _idx(idx) {\n        table.resize(62, vector<S>(v.size()));\n\
    \        for(int i = 0; i < v.size(); i++) table[0][i] = v[i];\n        for(int\
    \ i = 0; i < 61; i++){\n            for(int j = 0; j < v.size(); j++){\n     \
    \           table[i+1][j] = _op(table[i][j], table[i][_idx(table[i][j])]);\n \
    \           }\n        }\n    }        \n    \n    S query(S s, long long n){\n\
    \        for(int i = 0; i < 62; i++) if((n >> i) & 1){\n            s = _op(s,\
    \ table[i][_idx(s)]);\n        }\n        return s;\n    }\n    \n  private:\n\
    \    function<S(S, S)> _op;\n    function<int(S)> _idx;\n    vector<vector<S>>\
    \ table;\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/Doubling.cpp
  requiredBy: []
  timestamp: '2022-02-20 14:26:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/Doubling.cpp
layout: document
redirect_from:
- /library/lib/dp/Doubling.cpp
- /library/lib/dp/Doubling.cpp.html
title: lib/dp/Doubling.cpp
---
