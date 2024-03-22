---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rerooting.test.cpp
    title: test/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n\ntemplate< typename Data, typename T >\nstruct ReRooting {\n \n  struct\
    \ Node {\n    int to, rev;\n    Data data;\n  };\n \n  using F1 = function< T(T,\
    \ T) >;\n  using F2 = function< T(T, Data) >;\n \n  vector< vector< Node > > g;\n\
    \  vector< vector< T > > ldp, rdp;\n  vector<T> plus;\n  vector< int > lptr, rptr;\n\
    \  const F1 f1;\n  const F2 f2;\n  const T ident;\n \n  ReRooting(int n, const\
    \ F1 &f1, const F2 &f2, const T &ident) :\n      g(n), ldp(n), rdp(n), lptr(n),\
    \ rptr(n), plus(n,ident),f1(f1), f2(f2), ident(ident) {}\n\n void add_plus(vector<T>\
    \ plus_) {\n  plus=plus_;\n }\n\n  void add_edge(int u, int v, const Data &d)\
    \ {\n    g[u].emplace_back((Node) {v, (int) g[v].size(), d});\n    g[v].emplace_back((Node)\
    \ {u, (int) g[u].size() - 1, d});\n  }\n \n  void add_edge_bi(int u, int v, const\
    \ Data &d, const Data &e) {\n    g[u].emplace_back((Node) {v, (int) g[v].size(),\
    \ d});\n    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, e});\n  }\n \n\
    \ \n  T dfs(int idx, int par) {\n \n    while(lptr[idx] != par && lptr[idx] <\
    \ g[idx].size()) {\n      auto &e = g[idx][lptr[idx]];\n      ldp[idx][lptr[idx]\
    \ + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));\n      ++lptr[idx];\n\
    \    }\n\n\n    while(rptr[idx] != par && rptr[idx] >= 0) {\n      auto &e = g[idx][rptr[idx]];\n\
    \      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev),\
    \ e.data));\n      --rptr[idx];\n    }\n\n    if(par < 0) return f1(rdp[idx][0],plus[idx]);\n\
    \    return f1(f1(ldp[idx][par], rdp[idx][par + 1]),plus[idx]);\n  }\n \n  vector<\
    \ T > solve() {\n    for(int i = 0; i < g.size(); i++) {\n      ldp[i].assign(g[i].size()\
    \ + 1, ident);\n      rdp[i].assign(g[i].size() + 1, ident);\n      lptr[i] =\
    \ 0;\n      rptr[i] = (int) g[i].size() - 1;\n    }\n    vector< T > ret;\n  \
    \  for(int i = 0; i < g.size(); i++) {\n      ret.push_back(dfs(i, -1));\n   \
    \ }\n    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\nusing namespace std;\n\n\ntemplate<\
    \ typename Data, typename T >\nstruct ReRooting {\n \n  struct Node {\n    int\
    \ to, rev;\n    Data data;\n  };\n \n  using F1 = function< T(T, T) >;\n  using\
    \ F2 = function< T(T, Data) >;\n \n  vector< vector< Node > > g;\n  vector< vector<\
    \ T > > ldp, rdp;\n  vector<T> plus;\n  vector< int > lptr, rptr;\n  const F1\
    \ f1;\n  const F2 f2;\n  const T ident;\n \n  ReRooting(int n, const F1 &f1, const\
    \ F2 &f2, const T &ident) :\n      g(n), ldp(n), rdp(n), lptr(n), rptr(n), plus(n,ident),f1(f1),\
    \ f2(f2), ident(ident) {}\n\n void add_plus(vector<T> plus_) {\n  plus=plus_;\n\
    \ }\n\n  void add_edge(int u, int v, const Data &d) {\n    g[u].emplace_back((Node)\
    \ {v, (int) g[v].size(), d});\n    g[v].emplace_back((Node) {u, (int) g[u].size()\
    \ - 1, d});\n  }\n \n  void add_edge_bi(int u, int v, const Data &d, const Data\
    \ &e) {\n    g[u].emplace_back((Node) {v, (int) g[v].size(), d});\n    g[v].emplace_back((Node)\
    \ {u, (int) g[u].size() - 1, e});\n  }\n \n \n  T dfs(int idx, int par) {\n \n\
    \    while(lptr[idx] != par && lptr[idx] < g[idx].size()) {\n      auto &e = g[idx][lptr[idx]];\n\
    \      ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev),\
    \ e.data));\n      ++lptr[idx];\n    }\n\n\n    while(rptr[idx] != par && rptr[idx]\
    \ >= 0) {\n      auto &e = g[idx][rptr[idx]];\n      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx]\
    \ + 1], f2(dfs(e.to, e.rev), e.data));\n      --rptr[idx];\n    }\n\n    if(par\
    \ < 0) return f1(rdp[idx][0],plus[idx]);\n    return f1(f1(ldp[idx][par], rdp[idx][par\
    \ + 1]),plus[idx]);\n  }\n \n  vector< T > solve() {\n    for(int i = 0; i < g.size();\
    \ i++) {\n      ldp[i].assign(g[i].size() + 1, ident);\n      rdp[i].assign(g[i].size()\
    \ + 1, ident);\n      lptr[i] = 0;\n      rptr[i] = (int) g[i].size() - 1;\n \
    \   }\n    vector< T > ret;\n    for(int i = 0; i < g.size(); i++) {\n      ret.push_back(dfs(i,\
    \ -1));\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2024-02-17 16:46:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rerooting.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
redirect_from:
- /library/tree/rerooting.hpp
- /library/tree/rerooting.hpp.html
title: tree/rerooting.hpp
---
