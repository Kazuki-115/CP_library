---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/extGCD.test.cpp
    title: test/extGCD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extGCD.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\npair<long long, long long> extgcd(long long a, long long b) {\n  if\
    \ (b == 0) return make_pair(1, 0);\n  long long x, y;\n  tie(y, x) = extgcd(b,\
    \ a % b);\n  y -= a / b * x;\n  return make_pair(x, y);\n}\n\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\npair<long\
    \ long, long long> extgcd(long long a, long long b) {\n  if (b == 0) return make_pair(1,\
    \ 0);\n  long long x, y;\n  tie(y, x) = extgcd(b, a % b);\n  y -= a / b * x;\n\
    \  return make_pair(x, y);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extGCD.hpp
  requiredBy: []
  timestamp: '2024-02-10 23:01:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/extGCD.test.cpp
documentation_of: math/extGCD.hpp
layout: document
redirect_from:
- /library/math/extGCD.hpp
- /library/math/extGCD.hpp.html
title: math/extGCD.hpp
---
