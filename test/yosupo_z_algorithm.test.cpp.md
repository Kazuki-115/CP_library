---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo_z_algorithm.test.cpp\"\n#define PROBLEM   \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n\n#line 2 \"string/z_algorithm.hpp\"\
    \n#include<vector> \n#include<string>\nusing namespace std;\n\n\nstruct Z_algorithm\n\
    {\n  vector< int > prefix;\n\n  void build(const string &s)\n  {\n    prefix.assign(s.size(),\
    \ 0);\n    for(int i = 1, j = 0; i < s.size(); i++) {\n      if(i + prefix[i -\
    \ j] < j + prefix[j]) {\n        prefix[i] = prefix[i - j];\n      } else {\n\
    \        int k = max(0, j + prefix[j] - i);\n        while(i + k < s.size() &&\
    \ s[k] == s[i + k]) ++k;\n        prefix[i] = k;\n        j = i;\n      }\n  \
    \  }\n    prefix[0] = (int) s.size();\n  }\n\n  int operator[](const int k) const\n\
    \  {\n    return (prefix[k]);\n  }\n\n  size_t size()\n  {\n    return(prefix.size());\n\
    \  }\n};\n#line 4 \"test/yosupo_z_algorithm.test.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n \n string S;cin>>S;\n Z_algorithm z;\n z.build(S);\n\n for(ll\
    \ i=0;i<z.size();i++) {\n  cout<<z[i]<<\" \";\n }\n cout<<endl;\n \n}\n"
  code: "#define PROBLEM   \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../string/z_algorithm.hpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n \n string S;cin>>S;\n Z_algorithm z;\n z.build(S);\n\n for(ll\
    \ i=0;i<z.size();i++) {\n  cout<<z[i]<<\" \";\n }\n cout<<endl;\n \n}\n"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: test/yosupo_z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2024-02-10 15:48:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_z_algorithm.test.cpp
- /verify/test/yosupo_z_algorithm.test.cpp.html
title: test/yosupo_z_algorithm.test.cpp
---
