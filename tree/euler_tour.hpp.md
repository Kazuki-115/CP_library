---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/euler_tour.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n\n/// \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\nstruct EulerTour{\n\
    \  vector<int> order;\n  vector<pair<int,int>> sita;\n\n  EulerTour(vector<vector<int>>&\
    \ G, int root=0){\n    int n=G.size();\n    order.resize(n);\n    sita.resize(n);\n\
    \    int cur=0;\n\n    function<void(int,int)> dfs=[&](int v, int p){\n      order[v]=cur;\n\
    \      cur++;\n      for(auto nv: G[v]){\n        if(nv==p) continue;\n      \
    \  dfs(nv, v);\n      }\n      sita[v]=make_pair(order[v],cur-1);\n    };\n  \
    \  dfs(root, -1);\n  }\n};\n\n"
  code: " #pragma once\n\n#include<bits/stdc++.h>\nusing namespace std;\n\n\n/// \u30AA\
    \u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\nstruct EulerTour{\n  vector<int> order;\n\
    \  vector<pair<int,int>> sita;\n\n  EulerTour(vector<vector<int>>& G, int root=0){\n\
    \    int n=G.size();\n    order.resize(n);\n    sita.resize(n);\n    int cur=0;\n\
    \n    function<void(int,int)> dfs=[&](int v, int p){\n      order[v]=cur;\n  \
    \    cur++;\n      for(auto nv: G[v]){\n        if(nv==p) continue;\n        dfs(nv,\
    \ v);\n      }\n      sita[v]=make_pair(order[v],cur-1);\n    };\n    dfs(root,\
    \ -1);\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-02-15 01:16:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/euler_tour.hpp
layout: document
redirect_from:
- /library/tree/euler_tour.hpp
- /library/tree/euler_tour.hpp.html
title: tree/euler_tour.hpp
---
