---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree_diameter.test.cpp
    title: test/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_diameter.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nstd::pair<int, std::vector<int>> tree_diameter(\n    const\
    \ std::vector<std::vector<int>>& G) {\n    std::vector<int> to(G.size());\n\n\
    \    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<int, int> {\n\
    \        std::pair<int, int> ret(0, v);\n        for (int c : G[v]) {\n      \
    \      if (c == p) continue;\n            auto weight = dfs(dfs, c, v);\n    \
    \        ++weight.first;\n            if (ret < weight) {\n                ret\
    \ = weight;\n                to[v] = c;\n            }\n        }\n        return\
    \ ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second,\
    \ -1);\n    std::vector<int> path;\n    int v = p.second;\n    while (v != q.second)\
    \ {\n        path.push_back(v);\n        v = to[v];\n    }\n    path.push_back(v);\n\
    \    return {q.first, path};\n}\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>>\
    \ tree_diameter(\n    const std::vector<std::vector<std::pair<int, T>>>& G) {\n\
    \    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs, int\
    \ v, int p) -> std::pair<T, int> {\n        std::pair<T, int> ret(0, v);\n   \
    \     for (auto& [u, w] : G[v]) {\n            if (u == p) continue;\n       \
    \     auto weight = dfs(dfs, u, v);\n            weight.first += w;\n        \
    \    if (ret < weight) {\n                ret = weight;\n                to[v]\
    \ = u;\n            }\n        }\n        return ret;\n    };\n\n    auto p =\
    \ dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int>\
    \ path;\n    int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\nstd::pair<int,\
    \ std::vector<int>> tree_diameter(\n    const std::vector<std::vector<int>>& G)\
    \ {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
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
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-02-15 14:50:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree_diameter.test.cpp
documentation_of: tree/tree_diameter.hpp
layout: document
redirect_from:
- /library/tree/tree_diameter.hpp
- /library/tree/tree_diameter.hpp.html
title: tree/tree_diameter.hpp
---
