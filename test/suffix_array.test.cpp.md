---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/suffix_array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n#line\
    \ 2 \"string/suffix_array.hpp\"\n\n#line 4 \"string/suffix_array.hpp\"\nusing\
    \ namespace std;\n\n\n\nstruct SuffixArray {\n  vector< int > SA;\n  const string\
    \ s;\n\n  SuffixArray(const string &str) : s(str) {\n    SA.resize(s.size());\n\
    \    iota(begin(SA), end(SA), 0);\n    sort(begin(SA), end(SA), [&](int a, int\
    \ b) {\n      return s[a] == s[b] ? a > b : s[a] < s[b];\n    });\n    vector<\
    \ int > classes(s.size()), c(s.begin(), s.end()), cnt(s.size());\n    for(int\
    \ len = 1; len < s.size(); len <<= 1) {\n      for(int i = 0; i < s.size(); i++)\
    \ {\n        if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size()\
    \ && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {\n          classes[SA[i]]\
    \ = classes[SA[i - 1]];\n        } else {\n          classes[SA[i]] = i;\n   \
    \     }\n      }\n      iota(begin(cnt), end(cnt), 0);\n      copy(begin(SA),\
    \ end(SA), begin(c));\n      for(int i = 0; i < s.size(); i++) {\n        int\
    \ s1 = c[i] - len;\n        if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;\n      }\n\
    \      classes.swap(c);\n    }\n  }\n\n  int operator[](int k) const {\n    return\
    \ SA[k];\n  }\n\n  size_t size() const {\n    return s.size();\n  }\n\n  bool\
    \ lt_substr(const string &t, int si = 0, int ti = 0) {\n    int sn = (int) s.size(),\
    \ tn = (int) t.size();\n    while(si < sn && ti < tn) {\n      if(s[si] < t[ti])\
    \ return true;\n      if(s[si] > t[ti]) return false;\n      ++si, ++ti;\n   \
    \ }\n    return si >= sn && ti < tn;\n  }\n\n  int lower_bound(const string &t)\
    \ {\n    int low = -1, high = (int) SA.size();\n    while(high - low > 1) {\n\
    \      int mid = (low + high) / 2;\n      if(lt_substr(t, SA[mid])) low = mid;\n\
    \      else high = mid;\n    }\n    return high;\n  }\n\n  pair< int, int > lower_upper_bound(string\
    \ &t) {\n    int idx = lower_bound(t);\n    int low = idx - 1, high = (int) SA.size();\n\
    \    t.back()++;\n    while(high - low > 1) {\n      int mid = (low + high) /\
    \ 2;\n      if(lt_substr(t, SA[mid])) low = mid;\n      else high = mid;\n   \
    \ }\n    t.back()--;\n    return {idx, high};\n  }\n\n  void output() {\n    for(int\
    \ i = 0; i < size(); i++) {\n      cout << i << \": \" << s.substr(SA[i]) << endl;\n\
    \    }\n  }\n};\n#line 8 \"test/suffix_array.test.cpp\"\n\n\nint main() {\n  \
    \  ios::sync_with_stdio(false);\n  cin.tie(0);\n  \n  string S;cin>>S;\n  SuffixArray\
    \ sa(S);\n  for(ll i=0;i<S.size();i++) {\n    cout<<sa.SA[i]<<\" \";\n  }\n  cout<<endl;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n#include \"../string/suffix_array.hpp\"\
    \n\n\nint main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n  \n  string\
    \ S;cin>>S;\n  SuffixArray sa(S);\n  for(ll i=0;i<S.size();i++) {\n    cout<<sa.SA[i]<<\"\
    \ \";\n  }\n  cout<<endl;\n}\n\n"
  dependsOn:
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 20:36:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/test/suffix_array.test.cpp
- /verify/test/suffix_array.test.cpp.html
title: test/suffix_array.test.cpp
---
