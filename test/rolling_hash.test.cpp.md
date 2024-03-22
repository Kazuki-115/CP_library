---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/rolling_hash.test.cpp\"\n#define PROBLEM   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\n#line 4 \"string/rolling_hash.hpp\"\n\nclass rolling_hash\
    \ {\npublic:\n\tusing u64 = std::uint_fast64_t;\n\tusing size_type = std::uint_fast32_t;\n\
    \tusing i128 = __int128_t;\n\n\tstatic constexpr u64 MOD = (1uL << 61) - 1;\n\t\
    static constexpr u64 base = 20200213;\n\n\tstd::string str;\n\tstd::vector<u64>\
    \ hash_, pow;\n\nprivate:\n\tstatic constexpr u64 mask30 = (1ul << 30) - 1;\n\t\
    static constexpr u64 mask31 = (1ul << 31) - 1;\n\n\tu64 mul(i128 a, i128 b) const\
    \ {\n\t\ti128 t = a * b;\n\t\tt = (t >> 61) + (t & MOD);\n\t\t\n\t\tif(t >= MOD)\
    \ return t - MOD;\n\t\treturn t;\n\t}\n\tsize_type xorshift(size_type x) const\
    \ {\n\t\tx ^= x << 13;\n\t\tx ^= x >> 17;\n\t\tx ^= x << 5;\n\t\treturn x;\n\t\
    }\n\npublic:\n\trolling_hash(const rolling_hash &) = default;\n\trolling_hash(rolling_hash&&)\
    \ = default;\n\n\trolling_hash() : str() {};\n\n\trolling_hash(const std::string\
    \ & str) : str(str) {\n\t\thash_.resize(str.size() + 1, 0);\n\t\tpow.resize(str.size()\
    \ + 1, 1);\n\t\tfor(size_type i = 0; i < str.size(); i++) {\n\t\t\thash_[i + 1]\
    \ = mul(hash_[i], base) + xorshift(str[i] + 1);\n\t\t\tpow[i + 1] = mul(pow[i],\
    \ base);\n\t\t\tif(hash_[i + 1] >= MOD) hash_[i + 1] -= MOD;\n\t\t}\n\t}\n\n\t\
    u64 hash() const { return hash_.back(); }\n\tu64 hash(size_type l, size_type r)\
    \ const {\n\t\tu64 ret = MOD + hash_[r] - mul(hash_[l], pow[r - l]);\n\t\treturn\
    \ ret < MOD ? ret : ret - MOD;\n\t}\n\t\n\tsize_type size() const { return str.size();\
    \ }\n};\n#line 5 \"test/rolling_hash.test.cpp\"\nusing namespace std;\n\nusing\
    \ ll=long long;\n\n\n\n\n\nint main() {\n    string T,P;\n    cin>>T>>P;\n   \
    \ rolling_hash ht(T),hp(P);\nll N=T.size(),M=P.size();\n\n    for(ll i=0;i<N;i++)\
    \ {\n        if(i+M-1>=N) break;\n        if(ht.hash(i,i+M)==hp.hash(0,M)) cout<<i<<endl;\n\
    \    }\n}\n\n\n\n\n"
  code: "#define PROBLEM   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\n#include \"../string/rolling_hash.hpp\"\nusing namespace\
    \ std;\n\nusing ll=long long;\n\n\n\n\n\nint main() {\n    string T,P;\n    cin>>T>>P;\n\
    \    rolling_hash ht(T),hp(P);\nll N=T.size(),M=P.size();\n\n    for(ll i=0;i<N;i++)\
    \ {\n        if(i+M-1>=N) break;\n        if(ht.hash(i,i+M)==hp.hash(0,M)) cout<<i<<endl;\n\
    \    }\n}\n\n\n\n\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2024-02-10 15:23:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/rolling_hash.test.cpp
- /verify/test/rolling_hash.test.cpp.html
title: test/rolling_hash.test.cpp
---
