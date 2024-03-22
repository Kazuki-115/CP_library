---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.hpp
    title: tree/tree_diameter.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/tree_diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 2 \"tree/tree_diameter.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nstd::pair<int, std::vector<int>> tree_diameter(\n    const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(\n  \
    \  const std::vector<std::vector<std::pair<int, T>>>& G) {\n    std::vector<int>\
    \ to(G.size());\n\n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret(0, v);\n        for (auto& [u, w] : G[v])\
    \ {\n            if (u == p) continue;\n            auto weight = dfs(dfs, u,\
    \ v);\n            weight.first += w;\n            if (ret < weight) {\n     \
    \           ret = weight;\n                to[v] = u;\n            }\n       \
    \ }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q\
    \ = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 4 \"test/tree_diameter.test.cpp\"\
    \n\n#line 6 \"test/tree_diameter.test.cpp\"\nusing namespace std;\nusing ll =long\
    \ long;\n\n\n\nint main() {\n  ll N;cin>>N;\n  vector<vector<pair<int,ll>>> vec(N,vector<pair<int,ll>>\
    \ (0));\n  for(ll i=0;i<N-1;i++) {\n    ll a,b,c;cin>>a>>b>>c;\n    vec[a].push_back(make_pair(b,c));\n\
    \    vec[b].push_back(make_pair(a,c));\n  }\n\n\n  auto ans=tree_diameter<ll>(vec);\n\
    \n  cout<<ans.first<<\" \"<<ans.second.size()<<endl;\n  for(auto x:ans.second)\
    \ cout<<x<<\" \";\n  cout<<endl;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../tree/tree_diameter.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll =long long;\n\n\n\nint main() {\n  ll N;cin>>N;\n  vector<vector<pair<int,ll>>>\
    \ vec(N,vector<pair<int,ll>> (0));\n  for(ll i=0;i<N-1;i++) {\n    ll a,b,c;cin>>a>>b>>c;\n\
    \    vec[a].push_back(make_pair(b,c));\n    vec[b].push_back(make_pair(a,c));\n\
    \  }\n\n\n  auto ans=tree_diameter<ll>(vec);\n\n  cout<<ans.first<<\" \"<<ans.second.size()<<endl;\n\
    \  for(auto x:ans.second) cout<<x<<\" \";\n  cout<<endl;\n}\n\n"
  dependsOn:
  - tree/tree_diameter.hpp
  isVerificationFile: true
  path: test/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 14:50:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree_diameter.test.cpp
- /verify/test/tree_diameter.test.cpp.html
title: test/tree_diameter.test.cpp
---
