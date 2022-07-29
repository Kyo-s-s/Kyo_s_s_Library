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
  bundledCode: "#line 1 \"lib/data-structure/LCA.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<class T> struct LCA {\n  public:\n    LCA(int\
    \ n) : _n(n) {\n        G.resize(_n);\n    }\n\n    void add_edge(int s, int t){\
    \ add_edge(s, t, T(1)); }\n    void add_edge(int s, int t, T c){\n        G[s].push_back({t,\
    \ c});\n        G[t].push_back({s, c});\n    }\n\n    void build(int root = 0){\n\
    \        in.resize(_n, -1);\n        out.resize(_n, -1);\n        dist.resize(_n);\n\
    \        dist[root] = T(0);\n\n        auto dfs = [&](auto&& self, int now, int\
    \ bef, int depth) -> void {\n\n            in[now] = euler_tour.size();\n    \
    \        euler_tour.push_back({depth, now});\n\n            for(auto e: G[now])\
    \ if(e.to != bef){\n                dist[e.to] = dist[now] + e.cost;\n       \
    \         self(self, e.to, now, depth + 1);\n                euler_tour.push_back({depth,\
    \ now});\n            }\n            \n        };\n\n        dfs(dfs, root, -1,\
    \ 0);\n\n        log = 0;\n        while((1 << log) < euler_tour.size()) log++;\n\
    \        size = 1 << log;\n        d.resize(2 * size, e());\n\n        for(int\
    \ i = 0; i < euler_tour.size(); i++) d[size + i] = euler_tour[i];\n        for(int\
    \ i = size - 1; i >= 1; i--) update(i);\n\n    }\n\n    int query(int u, int v){\n\
    \        return prod(min(in[u], in[v]), max(in[u], in[v]) + 1).index;\n    }\n\
    \n    T get_path(int u, int v){\n        return dist[u] + dist[v] - 2 * dist[query(u,\
    \ v)];\n    }\n\n  private:\n    struct edge{ int to; T cost; };\n    struct S\
    \ { int depth, index; };\n    S op(S a, S b){ return (a.depth < b.depth ? a :\
    \ b); }\n    S e(){ return {1 << 28, 1 << 28}; }\n\n    int _n, log, size;\n \
    \   vector<vector<edge>> G;\n    vector<T> dist;\n    vector<int> in;\n    vector<S>\
    \ euler_tour;\n    vector<S> d;\n\n    void update(int k){ d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n    S prod(int l, int r){\n        S smr = e(), sml = e();\n\
    \        l += size; r += size;\n        while(l < r){\n            if(l & 1) sml\
    \ = op(sml, d[l++]);\n            if(r & 1) smr = op(d[--r], smr);\n         \
    \   l >>= 1; r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    \n\
    };\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T> struct\
    \ LCA {\n  public:\n    LCA(int n) : _n(n) {\n        G.resize(_n);\n    }\n\n\
    \    void add_edge(int s, int t){ add_edge(s, t, T(1)); }\n    void add_edge(int\
    \ s, int t, T c){\n        G[s].push_back({t, c});\n        G[t].push_back({s,\
    \ c});\n    }\n\n    void build(int root = 0){\n        in.resize(_n, -1);\n \
    \       out.resize(_n, -1);\n        dist.resize(_n);\n        dist[root] = T(0);\n\
    \n        auto dfs = [&](auto&& self, int now, int bef, int depth) -> void {\n\
    \n            in[now] = euler_tour.size();\n            euler_tour.push_back({depth,\
    \ now});\n\n            for(auto e: G[now]) if(e.to != bef){\n               \
    \ dist[e.to] = dist[now] + e.cost;\n                self(self, e.to, now, depth\
    \ + 1);\n                euler_tour.push_back({depth, now});\n            }\n\
    \            \n        };\n\n        dfs(dfs, root, -1, 0);\n\n        log = 0;\n\
    \        while((1 << log) < euler_tour.size()) log++;\n        size = 1 << log;\n\
    \        d.resize(2 * size, e());\n\n        for(int i = 0; i < euler_tour.size();\
    \ i++) d[size + i] = euler_tour[i];\n        for(int i = size - 1; i >= 1; i--)\
    \ update(i);\n\n    }\n\n    int query(int u, int v){\n        return prod(min(in[u],\
    \ in[v]), max(in[u], in[v]) + 1).index;\n    }\n\n    T get_path(int u, int v){\n\
    \        return dist[u] + dist[v] - 2 * dist[query(u, v)];\n    }\n\n  private:\n\
    \    struct edge{ int to; T cost; };\n    struct S { int depth, index; };\n  \
    \  S op(S a, S b){ return (a.depth < b.depth ? a : b); }\n    S e(){ return {1\
    \ << 28, 1 << 28}; }\n\n    int _n, log, size;\n    vector<vector<edge>> G;\n\
    \    vector<T> dist;\n    vector<int> in;\n    vector<S> euler_tour;\n    vector<S>\
    \ d;\n\n    void update(int k){ d[k] = op(d[2 * k], d[2 * k + 1]); }\n    S prod(int\
    \ l, int r){\n        S smr = e(), sml = e();\n        l += size; r += size;\n\
    \        while(l < r){\n            if(l & 1) sml = op(sml, d[l++]);\n       \
    \     if(r & 1) smr = op(d[--r], smr);\n            l >>= 1; r >>= 1;\n      \
    \  }\n        return op(sml, smr);\n    }\n    \n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/LCA.cpp
  requiredBy: []
  timestamp: '2022-03-23 13:26:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/LCA.cpp
layout: document
redirect_from:
- /library/lib/data-structure/LCA.cpp
- /library/lib/data-structure/LCA.cpp.html
title: lib/data-structure/LCA.cpp
---
