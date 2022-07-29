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
  bundledCode: "#line 1 \"lib/data-structure/Segtree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<class S, S (*op)(S, S), S (*e)()> struct Segtree\
    \ {\n  public:\n    Segtree() : Segtree(0) {}\n    Segtree(int n) : Segtree(vector<S>\
    \ (n, e())) {}\n    Segtree(const vector<S> &v) : n(int(v.size())) {\n       \
    \ while ((1 << log) < n) log++;\n        size = 1 << log;\n        d = vector<S>\
    \ (2 * size, e());\n        for (int i = 0; i < n; i++) d[size + i] = v[i];\n\
    \        for (int i = size - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        S sml = e(), smr = e();\n        l += size;\n        r += size;\n\
    \n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n   \
    \         if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n          \
    \  r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int l) {\n   \
    \     return max_right(l, [](S x) { return f(x); });\n    }\n    template <class\
    \ F> int max_right(int l, F f) {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n\
    \        if (l == n) return n;\n        l += size;\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) {\n   \
    \     return min_left(r, [](S x) { return f(x); });\n    }\n    template <class\
    \ F> int min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        S sm = e();\n    \
    \    do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n \
    \           if (!f(op(d[r], sm))) {\n                while (r < size) {\n    \
    \                r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int n, size, log = 0;\n    vector<S>\
    \ d;\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\n};\n\n\
    long long RMQop(long long a, long long b) { return max(a, b); }\nlong long RMQe()\
    \ { return -(1LL << 60); }\nusing RMQ = Segtree<long long, RMQop, RMQe>;\n\nlong\
    \ long RmQop(long long a, long long b) { return min(a, b); }\nlong long RmQe()\
    \ { return 1LL << 60; }\nusing RmQ = Segtree<long long, RmQop, RmQe>;\n\nlong\
    \ long RSQop(long long a, long long b) { return a + b; }\nlong long RSQe() { return\
    \ 0; }\nusing RSQ = Segtree<long long, RSQop, RSQe>;\n\n\nstruct MmS { long long\
    \ min, max, sum; };\nMmS MmSop(MmS a, MmS b){ return { min(a.min, b.min), max(a.max,\
    \ b.max), a.sum + b.sum }; }\nMmS MmSe(){ return {1LL << 60, -1ll << 60, 0 };\
    \ }\n\nstruct SegtreeMmS : Segtree<MmS, MmSop, MmSe> {\n    using Segtree::Segtree;\n\
    \    SegtreeMmS(int n){\n        vector<MmS> sv(n, MmSe());\n        (*this) =\
    \ SegtreeMmS(sv);\n    }\n    SegtreeMmS(vector<long long> v) {\n        int n\
    \ = v.size();\n        vector<MmS> sv(n);\n        for(int i = 0; i < n; i++)\
    \ sv[i] = {v[i], v[i], v[i]};\n        (*this) = SegtreeMmS(sv);\n    }\n    void\
    \ set(int p, long long x){\n        Segtree::set(p, {x, x, x});\n    }\n    long\
    \ long get(int p){\n        return Segtree::get(p).sum;\n    }\n};\n\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()> struct Segtree {\n  public:\n    Segtree() : Segtree(0) {}\n \
    \   Segtree(int n) : Segtree(vector<S> (n, e())) {}\n    Segtree(const vector<S>\
    \ &v) : n(int(v.size())) {\n        while ((1 << log) < n) log++;\n        size\
    \ = 1 << log;\n        d = vector<S> (2 * size, e());\n        for (int i = 0;\
    \ i < n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--)\
    \ update(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p\
    \ < n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p &&\
    \ p < n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n\
    \        l += size;\n        r += size;\n\n        while (l < r) {\n         \
    \   if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    template <bool\
    \ (*f)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int max_right(int l, F f) {\n     \
    \   assert(0 <= l && l <= n);\n        assert(f(e()));\n        if (l == n) return\
    \ n;\n        l += size;\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    l = (2 * l);\n                    if\
    \ (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n          \
    \              l++;\n                    }\n                }\n              \
    \  return l - size;\n            }\n            sm = op(sm, d[l]);\n         \
    \   l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n    template\
    \ <bool (*f)(S)> int min_left(int r) {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) {\n      \
    \  assert(0 <= r && r <= n);\n        assert(f(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int n, size, log = 0;\n    vector<S> d;\n    void update(int k) { d[k] =\
    \ op(d[2 * k], d[2 * k + 1]); }\n\n};\n\nlong long RMQop(long long a, long long\
    \ b) { return max(a, b); }\nlong long RMQe() { return -(1LL << 60); }\nusing RMQ\
    \ = Segtree<long long, RMQop, RMQe>;\n\nlong long RmQop(long long a, long long\
    \ b) { return min(a, b); }\nlong long RmQe() { return 1LL << 60; }\nusing RmQ\
    \ = Segtree<long long, RmQop, RmQe>;\n\nlong long RSQop(long long a, long long\
    \ b) { return a + b; }\nlong long RSQe() { return 0; }\nusing RSQ = Segtree<long\
    \ long, RSQop, RSQe>;\n\n\nstruct MmS { long long min, max, sum; };\nMmS MmSop(MmS\
    \ a, MmS b){ return { min(a.min, b.min), max(a.max, b.max), a.sum + b.sum }; }\n\
    MmS MmSe(){ return {1LL << 60, -1ll << 60, 0 }; }\n\nstruct SegtreeMmS : Segtree<MmS,\
    \ MmSop, MmSe> {\n    using Segtree::Segtree;\n    SegtreeMmS(int n){\n      \
    \  vector<MmS> sv(n, MmSe());\n        (*this) = SegtreeMmS(sv);\n    }\n    SegtreeMmS(vector<long\
    \ long> v) {\n        int n = v.size();\n        vector<MmS> sv(n);\n        for(int\
    \ i = 0; i < n; i++) sv[i] = {v[i], v[i], v[i]};\n        (*this) = SegtreeMmS(sv);\n\
    \    }\n    void set(int p, long long x){\n        Segtree::set(p, {x, x, x});\n\
    \    }\n    long long get(int p){\n        return Segtree::get(p).sum;\n    }\n\
    };\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/Segtree.cpp
  requiredBy: []
  timestamp: '2022-06-22 16:41:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/Segtree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/Segtree.cpp
- /library/lib/data-structure/Segtree.cpp.html
title: lib/data-structure/Segtree.cpp
---
