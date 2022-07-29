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
  bundledCode: "#line 1 \"lib/math/Eratos.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct Eratos{\n  public:\n    \n    Eratos(int _Eramax = 1e6){\n  \
    \      Eramax = _Eramax;\n        E.resize(Eramax + 1);\n        for(int i = 0;\
    \ i < Eramax + 1; i++) E[i] = i;\n        for(int i = 2; i < Eramax + 1; i++)\
    \ if(E[i] == i){\n            for(int j = 2 * i; j < Eramax + 1; j += i) E[j]\
    \ = i;\n        }\n        E[1] = -1;\n    }\n\n    vector<int> factorize(int\
    \ n){\n        assert(n <= Eramax);\n        vector<int> ret;\n        while(n\
    \ != 1){\n            ret.push_back(E[n]);\n            n /= E[n];\n        }\n\
    \        return ret;\n    }\n\n    vector<int> divisor(int n){\n        assert(n\
    \ <= Eramax);\n        vector<int> fact = factorize(n);\n        map<int, int>\
    \ cnt;\n        vector<int> list;\n        for(auto x: fact) cnt[x]++;\n     \
    \   for(auto [k, v]: cnt) list.push_back(k);\n        vector<int> ret;\n\n   \
    \     auto dfs = [&](auto&& self, int n, int x) -> void {\n            if(n ==\
    \ list.size()){\n                ret.pb(x); return;\n            }\n         \
    \   for(int u = 0; u <= cnt[list[n]]; u++){\n                self(self, n + 1,\
    \ x * pow(list[n], u));\n            }\n        };\n        dfs(dfs, 0, 1);\n\
    \        return ret;\n    }\n\n    bool is_prime(int x){\n        assert(x <=\
    \ Eramax);\n        return x == E[x];\n    }\n\n  private:\n    vector<int> E;\n\
    \    int Eramax;\n    int pow(int a, int n){\n        int ret = 1;\n        while(n\
    \ > 0){\n            if(n & 1) ret = ret * a;\n            a *= a;\n         \
    \   n >>= 1;\n        }\n        return ret;\n    }\n\n};\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Eratos{\n  public:\n\
    \    \n    Eratos(int _Eramax = 1e6){\n        Eramax = _Eramax;\n        E.resize(Eramax\
    \ + 1);\n        for(int i = 0; i < Eramax + 1; i++) E[i] = i;\n        for(int\
    \ i = 2; i < Eramax + 1; i++) if(E[i] == i){\n            for(int j = 2 * i; j\
    \ < Eramax + 1; j += i) E[j] = i;\n        }\n        E[1] = -1;\n    }\n\n  \
    \  vector<int> factorize(int n){\n        assert(n <= Eramax);\n        vector<int>\
    \ ret;\n        while(n != 1){\n            ret.push_back(E[n]);\n           \
    \ n /= E[n];\n        }\n        return ret;\n    }\n\n    vector<int> divisor(int\
    \ n){\n        assert(n <= Eramax);\n        vector<int> fact = factorize(n);\n\
    \        map<int, int> cnt;\n        vector<int> list;\n        for(auto x: fact)\
    \ cnt[x]++;\n        for(auto [k, v]: cnt) list.push_back(k);\n        vector<int>\
    \ ret;\n\n        auto dfs = [&](auto&& self, int n, int x) -> void {\n      \
    \      if(n == list.size()){\n                ret.pb(x); return;\n           \
    \ }\n            for(int u = 0; u <= cnt[list[n]]; u++){\n                self(self,\
    \ n + 1, x * pow(list[n], u));\n            }\n        };\n        dfs(dfs, 0,\
    \ 1);\n        return ret;\n    }\n\n    bool is_prime(int x){\n        assert(x\
    \ <= Eramax);\n        return x == E[x];\n    }\n\n  private:\n    vector<int>\
    \ E;\n    int Eramax;\n    int pow(int a, int n){\n        int ret = 1;\n    \
    \    while(n > 0){\n            if(n & 1) ret = ret * a;\n            a *= a;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Eratos.cpp
  requiredBy: []
  timestamp: '2022-04-23 23:57:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Eratos.cpp
layout: document
redirect_from:
- /library/lib/math/Eratos.cpp
- /library/lib/math/Eratos.cpp.html
title: lib/math/Eratos.cpp
---
