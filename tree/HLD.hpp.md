---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/HLD.test.cpp
    title: test/HLD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/HLD.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n\nstruct HeavyLightDecomposition {\n  vector<vector<int>> &g;\n  vector<\
    \ int > sz, in, out, head, rev, par;\n\n  HeavyLightDecomposition(vector<vector<int>>\
    \ &g) :\n      g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()),\
    \ rev(g.size()), par(g.size()) {}\n\n  void dfs_sz(int idx, int p) {\n    par[idx]\
    \ = p;\n    sz[idx] = 1;\n    if(g[idx].size() && g[idx][0] == p) swap(g[idx][0],\
    \ g[idx].back());\n    for(auto &to : g[idx]) {\n      if(to == p) continue;\n\
    \      dfs_sz(to, idx);\n      sz[idx] += sz[to];\n      if(sz[g[idx][0]] < sz[to])\
    \ swap(g[idx][0], to);\n    }\n  }\n\n  void dfs_hld(int idx, int par, int &times)\
    \ {\n    in[idx] = times++;\n    rev[in[idx]] = idx;\n    for(auto &to : g[idx])\
    \ {\n      if(to == par) continue;\n      head[to] = (g[idx][0] == to ? head[idx]\
    \ : to);\n      dfs_hld(to, idx, times);\n    }\n    out[idx] = times;\n  }\n\n\
    \  void build() {\n    dfs_sz(0, -1);\n    int t = 0;\n    dfs_hld(0, -1, t);\n\
    \  }\n\n  int la(int v, int k) {\n    while(1) {\n      int u = head[v];\n   \
    \   if(in[v] - k >= in[u]) return rev[in[v] - k];\n      k -= in[v] - in[u] +\
    \ 1;\n      v = par[u];\n    }\n  }\n\n  int lca(int u, int v) {\n    for(;; v\
    \ = par[head[v]]) {\n      if(in[u] > in[v]) swap(u, v);\n      if(head[u] ==\
    \ head[v]) return u;\n    }\n  }\n\n  template< typename T, typename Q, typename\
    \ F >\n  T query(int u, int v, const T &ti, const Q &q, const F &f, bool edge\
    \ = false) {\n    T l = ti, r = ti;\n    for(;; v = par[head[v]]) {\n      if(in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n      if(head[u] == head[v]) break;\n    \
    \  l = f(q(in[head[v]], in[v] + 1), l);\n    }\n    return f(f(q(in[u] + edge,\
    \ in[v] + 1), l), r);\n//  return {f(q(in[u] + edge, in[v] + 1), l), r};\n  }\n\
    \n  template< typename Q >\n  void add(int u, int v, const Q &q, bool edge = false)\
    \ {\n    for(;; v = par[head[v]]) {\n      if(in[u] > in[v]) swap(u, v);\n   \
    \   if(head[u] == head[v]) break;\n      q(in[head[v]], in[v] + 1);\n    }\n \
    \   q(in[u] + edge, in[v] + 1);\n  }\n};\n"
  code: " #pragma once\n\n#include<bits/stdc++.h>\nusing namespace std;\n\n\nstruct\
    \ HeavyLightDecomposition {\n  vector<vector<int>> &g;\n  vector< int > sz, in,\
    \ out, head, rev, par;\n\n  HeavyLightDecomposition(vector<vector<int>> &g) :\n\
    \      g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()),\
    \ par(g.size()) {}\n\n  void dfs_sz(int idx, int p) {\n    par[idx] = p;\n   \
    \ sz[idx] = 1;\n    if(g[idx].size() && g[idx][0] == p) swap(g[idx][0], g[idx].back());\n\
    \    for(auto &to : g[idx]) {\n      if(to == p) continue;\n      dfs_sz(to, idx);\n\
    \      sz[idx] += sz[to];\n      if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);\n\
    \    }\n  }\n\n  void dfs_hld(int idx, int par, int &times) {\n    in[idx] = times++;\n\
    \    rev[in[idx]] = idx;\n    for(auto &to : g[idx]) {\n      if(to == par) continue;\n\
    \      head[to] = (g[idx][0] == to ? head[idx] : to);\n      dfs_hld(to, idx,\
    \ times);\n    }\n    out[idx] = times;\n  }\n\n  void build() {\n    dfs_sz(0,\
    \ -1);\n    int t = 0;\n    dfs_hld(0, -1, t);\n  }\n\n  int la(int v, int k)\
    \ {\n    while(1) {\n      int u = head[v];\n      if(in[v] - k >= in[u]) return\
    \ rev[in[v] - k];\n      k -= in[v] - in[u] + 1;\n      v = par[u];\n    }\n \
    \ }\n\n  int lca(int u, int v) {\n    for(;; v = par[head[v]]) {\n      if(in[u]\
    \ > in[v]) swap(u, v);\n      if(head[u] == head[v]) return u;\n    }\n  }\n\n\
    \  template< typename T, typename Q, typename F >\n  T query(int u, int v, const\
    \ T &ti, const Q &q, const F &f, bool edge = false) {\n    T l = ti, r = ti;\n\
    \    for(;; v = par[head[v]]) {\n      if(in[u] > in[v]) swap(u, v), swap(l, r);\n\
    \      if(head[u] == head[v]) break;\n      l = f(q(in[head[v]], in[v] + 1), l);\n\
    \    }\n    return f(f(q(in[u] + edge, in[v] + 1), l), r);\n//  return {f(q(in[u]\
    \ + edge, in[v] + 1), l), r};\n  }\n\n  template< typename Q >\n  void add(int\
    \ u, int v, const Q &q, bool edge = false) {\n    for(;; v = par[head[v]]) {\n\
    \      if(in[u] > in[v]) swap(u, v);\n      if(head[u] == head[v]) break;\n  \
    \    q(in[head[v]], in[v] + 1);\n    }\n    q(in[u] + edge, in[v] + 1);\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/HLD.hpp
  requiredBy: []
  timestamp: '2024-03-21 21:46:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/HLD.test.cpp
documentation_of: tree/HLD.hpp
layout: document
redirect_from:
- /library/tree/HLD.hpp
- /library/tree/HLD.hpp.html
title: tree/HLD.hpp
---
