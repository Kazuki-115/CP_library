---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segtree.test.cpp
    title: test/lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rerooting.test.cpp
    title: test/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mint998.hpp\"\n#include <bits/stdc++.h> \nusing namespace\
    \ std;\nusing ll =long long;\n\nll INF=2e18;\n\n\ntemplate<int mod> \nclass modint\
    \ {\n    long long x;\npublic:\n    modint(long long x=0) : x((x%mod+mod)%mod)\
    \ {}\n    modint operator-() const { \n      return modint(-x);\n    }\n    modint&\
    \ operator+=(const modint& a) {\n        if ((x += a.x) >= mod) x -= mod;\n  \
    \      return *this;\n    }\n    modint& operator-=(const modint& a) {\n     \
    \   if ((x += mod-a.x) >= mod) x -= mod;\n        return *this;\n    }\n    modint&\
    \ operator*=(const  modint& a) {\n        (x *= a.x) %= mod;\n        return *this;\n\
    \    }\n    modint operator+(const modint& a) const {\n        modint res(*this);\n\
    \        return res+=a;\n    }\n    modint operator-(const modint& a) const {\n\
    \        modint res(*this);\n        return res-=a;\n    }\n    modint operator*(const\
    \ modint& a) const {\n        modint res(*this);\n        return res*=a;\n   \
    \ }\n    modint pow(ll t) const {\n        if (!t) return 1;\n        modint a\
    \ = pow(t>>1);\n        a *= a;\n        if (t&1) a *= *this;\n        return\
    \ a;\n    }\n    // for prime mod\n    modint inv() const {\n        return pow(mod-2);\n\
    \    }\n    modint& operator/=(const modint& a) {\n        return (*this) *= a.inv();\n\
    \    }\n    modint operator/(const modint& a) const {\n        modint res(*this);\n\
    \        return res/=a;\n    }\n\n    bool operator==(const modint &a) const {\n\
    \        modint res(*this);\n        return res.x==a.x;\n    }\n\n    bool operator!=(const\
    \ modint &a) const {\n        modint res(*this);\n        return res.x!=a.x;\n\
    \    }\n\n\n    friend ostream& operator<<(ostream& os, const modint& m){\n  \
    \      os << m.x;\n        return os;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h> \nusing namespace std;\nusing ll =long\
    \ long;\n\nll INF=2e18;\n\n\ntemplate<int mod> \nclass modint {\n    long long\
    \ x;\npublic:\n    modint(long long x=0) : x((x%mod+mod)%mod) {}\n    modint operator-()\
    \ const { \n      return modint(-x);\n    }\n    modint& operator+=(const modint&\
    \ a) {\n        if ((x += a.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    modint& operator-=(const modint& a) {\n        if ((x += mod-a.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    modint& operator*=(const  modint&\
    \ a) {\n        (x *= a.x) %= mod;\n        return *this;\n    }\n    modint operator+(const\
    \ modint& a) const {\n        modint res(*this);\n        return res+=a;\n   \
    \ }\n    modint operator-(const modint& a) const {\n        modint res(*this);\n\
    \        return res-=a;\n    }\n    modint operator*(const modint& a) const {\n\
    \        modint res(*this);\n        return res*=a;\n    }\n    modint pow(ll\
    \ t) const {\n        if (!t) return 1;\n        modint a = pow(t>>1);\n     \
    \   a *= a;\n        if (t&1) a *= *this;\n        return a;\n    }\n    // for\
    \ prime mod\n    modint inv() const {\n        return pow(mod-2);\n    }\n   \
    \ modint& operator/=(const modint& a) {\n        return (*this) *= a.inv();\n\
    \    }\n    modint operator/(const modint& a) const {\n        modint res(*this);\n\
    \        return res/=a;\n    }\n\n    bool operator==(const modint &a) const {\n\
    \        modint res(*this);\n        return res.x==a.x;\n    }\n\n    bool operator!=(const\
    \ modint &a) const {\n        modint res(*this);\n        return res.x!=a.x;\n\
    \    }\n\n\n    friend ostream& operator<<(ostream& os, const modint& m){\n  \
    \      os << m.x;\n        return os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mint998.hpp
  requiredBy: []
  timestamp: '2024-02-10 14:37:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rerooting.test.cpp
  - test/lazy_segtree.test.cpp
documentation_of: math/mint998.hpp
layout: document
redirect_from:
- /library/math/mint998.hpp
- /library/math/mint998.hpp.html
title: math/mint998.hpp
---
