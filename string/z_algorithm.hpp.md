---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_z_algorithm.test.cpp
    title: test/yosupo_z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n#include<vector> \n#include<string>\n\
    using namespace std;\n\n\nstruct Z_algorithm\n{\n  vector< int > prefix;\n\n \
    \ void build(const string &s)\n  {\n    prefix.assign(s.size(), 0);\n    for(int\
    \ i = 1, j = 0; i < s.size(); i++) {\n      if(i + prefix[i - j] < j + prefix[j])\
    \ {\n        prefix[i] = prefix[i - j];\n      } else {\n        int k = max(0,\
    \ j + prefix[j] - i);\n        while(i + k < s.size() && s[k] == s[i + k]) ++k;\n\
    \        prefix[i] = k;\n        j = i;\n      }\n    }\n    prefix[0] = (int)\
    \ s.size();\n  }\n\n  int operator[](const int k) const\n  {\n    return (prefix[k]);\n\
    \  }\n\n  size_t size()\n  {\n    return(prefix.size());\n  }\n};\n"
  code: "#pragma once\n#include<vector> \n#include<string>\nusing namespace std;\n\
    \n\nstruct Z_algorithm\n{\n  vector< int > prefix;\n\n  void build(const string\
    \ &s)\n  {\n    prefix.assign(s.size(), 0);\n    for(int i = 1, j = 0; i < s.size();\
    \ i++) {\n      if(i + prefix[i - j] < j + prefix[j]) {\n        prefix[i] = prefix[i\
    \ - j];\n      } else {\n        int k = max(0, j + prefix[j] - i);\n        while(i\
    \ + k < s.size() && s[k] == s[i + k]) ++k;\n        prefix[i] = k;\n        j\
    \ = i;\n      }\n    }\n    prefix[0] = (int) s.size();\n  }\n\n  int operator[](const\
    \ int k) const\n  {\n    return (prefix[k]);\n  }\n\n  size_t size()\n  {\n  \
    \  return(prefix.size());\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-02-10 15:48:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_z_algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
