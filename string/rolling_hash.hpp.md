---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rolling_hash.test.cpp
    title: test/rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n#include <string>\n#include <vector>\n\
    #include <cstdint>\n\nclass rolling_hash {\npublic:\n\tusing u64 = std::uint_fast64_t;\n\
    \tusing size_type = std::uint_fast32_t;\n\tusing i128 = __int128_t;\n\n\tstatic\
    \ constexpr u64 MOD = (1uL << 61) - 1;\n\tstatic constexpr u64 base = 20200213;\n\
    \n\tstd::string str;\n\tstd::vector<u64> hash_, pow;\n\nprivate:\n\tstatic constexpr\
    \ u64 mask30 = (1ul << 30) - 1;\n\tstatic constexpr u64 mask31 = (1ul << 31) -\
    \ 1;\n\n\tu64 mul(i128 a, i128 b) const {\n\t\ti128 t = a * b;\n\t\tt = (t >>\
    \ 61) + (t & MOD);\n\t\t\n\t\tif(t >= MOD) return t - MOD;\n\t\treturn t;\n\t\
    }\n\tsize_type xorshift(size_type x) const {\n\t\tx ^= x << 13;\n\t\tx ^= x >>\
    \ 17;\n\t\tx ^= x << 5;\n\t\treturn x;\n\t}\n\npublic:\n\trolling_hash(const rolling_hash\
    \ &) = default;\n\trolling_hash(rolling_hash&&) = default;\n\n\trolling_hash()\
    \ : str() {};\n\n\trolling_hash(const std::string & str) : str(str) {\n\t\thash_.resize(str.size()\
    \ + 1, 0);\n\t\tpow.resize(str.size() + 1, 1);\n\t\tfor(size_type i = 0; i < str.size();\
    \ i++) {\n\t\t\thash_[i + 1] = mul(hash_[i], base) + xorshift(str[i] + 1);\n\t\
    \t\tpow[i + 1] = mul(pow[i], base);\n\t\t\tif(hash_[i + 1] >= MOD) hash_[i + 1]\
    \ -= MOD;\n\t\t}\n\t}\n\n\tu64 hash() const { return hash_.back(); }\n\tu64 hash(size_type\
    \ l, size_type r) const {\n\t\tu64 ret = MOD + hash_[r] - mul(hash_[l], pow[r\
    \ - l]);\n\t\treturn ret < MOD ? ret : ret - MOD;\n\t}\n\t\n\tsize_type size()\
    \ const { return str.size(); }\n};\n"
  code: "#include <string>\n#include <vector>\n#include <cstdint>\n\nclass rolling_hash\
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
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-02-10 14:37:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rolling_hash.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
