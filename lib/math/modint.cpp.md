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
  bundledCode: "#line 1 \"lib/math/modint.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<int m> struct StaticModint{\n    using mint = StaticModint;\n\
    \  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    StaticModint()\
    \ : _v(0) {}\n    template <class T>\n    StaticModint(T v) {\n        long long\
    \ x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n\n    unsigned int val() const { return\
    \ _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       assert(_v);\n        return pow(umod() - 2);\n    }\n\n    friend mint\
    \ operator+(const mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n\
    \    }\n    friend mint operator-(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n    friend mint\
    \ operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n\
    \    }\n    friend bool operator==(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n    friend ostream\
    \ &operator<<(ostream &os, mint &x) {\n        os << x.val();\n        return\
    \ (os);\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned\
    \ int umod() { return m; }\n\n};\n\nusing Modint998244353 = StaticModint<998244353>;\n\
    using Modint1000000007 = StaticModint<1000000007>;\n\nusing Mint = Modint998244353;\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<int m> struct\
    \ StaticModint{\n    using mint = StaticModint;\n  public:\n    static constexpr\
    \ int mod() { return m; }\n    static mint raw(int v) {\n        mint x;\n   \
    \     x._v = v;\n        return x;\n    }\n\n    StaticModint() : _v(0) {}\n \
    \   template <class T>\n    StaticModint(T v) {\n        long long x = (long long)(v\
    \ % (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n\n    unsigned int val() const { return _v; }\n\n    mint&\
    \ operator++() {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return\
    \ *this;\n    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n    mint operator++(int) {\n   \
    \     mint result = *this;\n        ++*this;\n        return result;\n    }\n\
    \    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n\n    mint& operator+=(const mint& rhs) {\n  \
    \      _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    mint&\
    \ operator*=(const mint& rhs) {\n        unsigned long long z = _v;\n        z\
    \ *= rhs._v;\n        _v = (unsigned int)(z % umod());\n        return *this;\n\
    \    }\n    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv();\
    \ }\n\n    mint operator+() const { return *this; }\n    mint operator-() const\
    \ { return mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        mint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    mint inv() const {\n        assert(_v);\n        return\
    \ pow(umod() - 2);\n    }\n\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\n    friend ostream &operator<<(ostream &os, mint &x) {\n\
    \        os << x.val();\n        return (os);\n    }\n\n  private:\n    unsigned\
    \ int _v;\n    static constexpr unsigned int umod() { return m; }\n\n};\n\nusing\
    \ Modint998244353 = StaticModint<998244353>;\nusing Modint1000000007 = StaticModint<1000000007>;\n\
    \nusing Mint = Modint998244353;"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modint.cpp
  requiredBy: []
  timestamp: '2022-04-16 18:47:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/modint.cpp
layout: document
redirect_from:
- /library/lib/math/modint.cpp
- /library/lib/math/modint.cpp.html
title: lib/math/modint.cpp
---