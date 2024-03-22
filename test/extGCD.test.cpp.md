---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extGCD.hpp
    title: math/extGCD.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja
  bundledCode: "#line 1 \"test/extGCD.test.cpp\"\n#define PROBLEM   \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja\"\
    \n#line 2 \"math/extGCD.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    \npair<long long, long long> extgcd(long long a, long long b) {\n  if (b == 0)\
    \ return make_pair(1, 0);\n  long long x, y;\n  tie(y, x) = extgcd(b, a % b);\n\
    \  y -= a / b * x;\n  return make_pair(x, y);\n}\n\n#line 3 \"test/extGCD.test.cpp\"\
    \n\n#line 5 \"test/extGCD.test.cpp\"\nusing namespace std;\n\nusing ll=long long;\n\
    \nint main() {\n    ll a,b;cin>>a>>b;\n    \nauto p=extgcd(a,b);\ncout<<p.first<<\"\
    \ \"<<p.second<<endl;\n}\n\n"
  code: "#define PROBLEM   \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja\"\
    \n#include \"../math/extGCD.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll=long long;\n\nint main() {\n    ll a,b;cin>>a>>b;\n    \nauto\
    \ p=extgcd(a,b);\ncout<<p.first<<\" \"<<p.second<<endl;\n}\n\n"
  dependsOn:
  - math/extGCD.hpp
  isVerificationFile: true
  path: test/extGCD.test.cpp
  requiredBy: []
  timestamp: '2024-02-10 23:01:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/extGCD.test.cpp
layout: document
redirect_from:
- /verify/test/extGCD.test.cpp
- /verify/test/extGCD.test.cpp.html
title: test/extGCD.test.cpp
---
