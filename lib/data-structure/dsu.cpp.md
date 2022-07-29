---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/document_ja/dsu.html
  bundledCode: "#line 1 \"lib/data-structure/dsu.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// https://atcoder.github.io/ac-library/document_ja/dsu.html\
    \ \n\nstruct dsu{\n  public:\n    dsu() : _n(0) {}\n    dsu(int n):  _n(n), parent(n,\
    \ -1) {}\n\n    int marge(int a, int b){\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if(x == y) return x;\n        if(-parent[x] < -parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        return\
    \ x;\n    }\n\n    bool same(int a, int b){\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n \
    \   }\n\n    int leader(int a){\n        assert(0 <= a && a < _n);\n        if(parent[a]\
    \ < 0) return a;\n        return parent[a] = leader(parent[a]);\n    }\n\n   \
    \ int size(int a){\n        assert(0 <= a && a < _n);\n        return -parent[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups(){\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \    \n  private:\n    int _n;\n    // root node: -1 * component size\n    //\
    \ otherwise: parent\n    std::vector<int> parent;\n};\n\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// https://atcoder.github.io/ac-library/document_ja/dsu.html\
    \ \n\nstruct dsu{\n  public:\n    dsu() : _n(0) {}\n    dsu(int n):  _n(n), parent(n,\
    \ -1) {}\n\n    int marge(int a, int b){\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if(x == y) return x;\n        if(-parent[x] < -parent[y]) std::swap(x,\
    \ y);\n        parent[x] += parent[y];\n        parent[y] = x;\n        return\
    \ x;\n    }\n\n    bool same(int a, int b){\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n \
    \   }\n\n    int leader(int a){\n        assert(0 <= a && a < _n);\n        if(parent[a]\
    \ < 0) return a;\n        return parent[a] = leader(parent[a]);\n    }\n\n   \
    \ int size(int a){\n        assert(0 <= a && a < _n);\n        return -parent[leader(a)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups(){\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \    \n  private:\n    int _n;\n    // root node: -1 * component size\n    //\
    \ otherwise: parent\n    std::vector<int> parent;\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/dsu.cpp
  requiredBy: []
  timestamp: '2022-02-01 16:44:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/dsu.cpp
layout: document
redirect_from:
- /library/lib/data-structure/dsu.cpp
- /library/lib/data-structure/dsu.cpp.html
title: lib/data-structure/dsu.cpp
---
