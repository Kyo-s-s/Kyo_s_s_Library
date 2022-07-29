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
  bundledCode: "#line 1 \"lib/math/Matrix.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<class T> struct Matrix {\n  public:\n    int n, m;\n    vector<vector<T>>\
    \ M;\n\n    Matrix() : n(0), m(0) { init(); }\n    Matrix(int _n, int _m) : n(_n),\
    \ m(_m) { init(); }\n    Matrix(int _n) : n(_n), m(_n) { init(); }\n\n    void\
    \ init(){ M.resize(n, vector<T>(m, 0)); }\n\n    inline const vector<T> &operator[](int\
    \ k) const { return (M.at(k)); }\n    inline vector<T> &operator[](int k) { return\
    \ (M.at(k)); }\n\n    static Matrix I(int n) {\n        Matrix mat(n);\n     \
    \   for(int i = 0; i < n; i++) mat[i][i] = 1;\n        return (mat);\n    }\n\n\
    \    Matrix operator+=(const Matrix &B) {\n        assert(n == B.n && m == B.m);\n\
    \        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] +=\
    \ B[i][j];\n        return (*this);\n    }\n\n    Matrix operator-=(const Matrix\
    \ &B) {\n        assert(n == B.n && m == B.m);\n        for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n\
    \    }\n\n    Matrix operator*=(const Matrix &B) {\n        assert(m == B.n);\n\
    \        m = B.m;\n        vector<vector<T>> C(n, vector<T>(B.m, 0));\n      \
    \  for(int i = 0; i < n; i++) for(int j = 0; j < B.m; j++) for(int k = 0; k <\
    \ B.n; k++) C[i][j] += (*this)[i][k] * B[k][j];\n        M.swap(C);\n        return\
    \ (*this);\n    }\n\n    Matrix pow(long long k) {\n        assert(n == m);\n\
    \        Matrix B = Matrix::I(n);\n        while(k > 0) {\n            if(k &\
    \ 1) B *= *this;\n            *this *= *this;\n            k >>= 1LL;\n      \
    \  }\n        return B;\n    }\n\n    Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) +=B); }\n    Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -=B); }\n    Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *=B); }\n\n    friend ostream &operator<<(ostream &os,\
    \ Matrix &p) {\n        for(int i = 0; i < p.n; i++) {\n            os << \"[\"\
    ;\n            for(int j = 0; j < p.m; j++){\n                os << p[i][j] <<\
    \ (j == p.m - 1 ? \"]\\n\" : \", \");\n            }\n        }\n        return\
    \ (os);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T> struct\
    \ Matrix {\n  public:\n    int n, m;\n    vector<vector<T>> M;\n\n    Matrix()\
    \ : n(0), m(0) { init(); }\n    Matrix(int _n, int _m) : n(_n), m(_m) { init();\
    \ }\n    Matrix(int _n) : n(_n), m(_n) { init(); }\n\n    void init(){ M.resize(n,\
    \ vector<T>(m, 0)); }\n\n    inline const vector<T> &operator[](int k) const {\
    \ return (M.at(k)); }\n    inline vector<T> &operator[](int k) { return (M.at(k));\
    \ }\n\n    static Matrix I(int n) {\n        Matrix mat(n);\n        for(int i\
    \ = 0; i < n; i++) mat[i][i] = 1;\n        return (mat);\n    }\n\n    Matrix\
    \ operator+=(const Matrix &B) {\n        assert(n == B.n && m == B.m);\n     \
    \   for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix operator-=(const Matrix &B) {\n\
    \        assert(n == B.n && m == B.m);\n        for(int i = 0; i < n; i++) for(int\
    \ j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n    }\n\
    \n    Matrix operator*=(const Matrix &B) {\n        assert(m == B.n);\n      \
    \  m = B.m;\n        vector<vector<T>> C(n, vector<T>(B.m, 0));\n        for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < B.m; j++) for(int k = 0; k < B.n; k++)\
    \ C[i][j] += (*this)[i][k] * B[k][j];\n        M.swap(C);\n        return (*this);\n\
    \    }\n\n    Matrix pow(long long k) {\n        assert(n == m);\n        Matrix\
    \ B = Matrix::I(n);\n        while(k > 0) {\n            if(k & 1) B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        return\
    \ B;\n    }\n\n    Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ +=B); }\n    Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -=B); }\n    Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *=B); }\n\n    friend ostream &operator<<(ostream &os, Matrix &p) {\n      \
    \  for(int i = 0; i < p.n; i++) {\n            os << \"[\";\n            for(int\
    \ j = 0; j < p.m; j++){\n                os << p[i][j] << (j == p.m - 1 ? \"]\\\
    n\" : \", \");\n            }\n        }\n        return (os);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Matrix.cpp
  requiredBy: []
  timestamp: '2022-06-23 12:24:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Matrix.cpp
layout: document
redirect_from:
- /library/lib/math/Matrix.cpp
- /library/lib/math/Matrix.cpp.html
title: lib/math/Matrix.cpp
---
