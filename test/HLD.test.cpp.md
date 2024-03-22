---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/HLD.hpp
    title: tree/HLD.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/HLD.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 2 \"tree/HLD.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace std;\n\
    \n\nstruct HeavyLightDecomposition {\n  vector<vector<int>> &g;\n  vector< int\
    \ > sz, in, out, head, rev, par;\n\n  HeavyLightDecomposition(vector<vector<int>>\
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
    \   q(in[u] + edge, in[v] + 1);\n  }\n};\n#line 4 \"test/HLD.test.cpp\"\n\n#line\
    \ 6 \"test/HLD.test.cpp\"\nusing namespace std;\nusing ll =long long;\n\n\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n  \nll N,Q;cin>>N>>Q;\n\
    vector<vector<int>> g(N,vector<int> (0));\nfor(ll i=1;i<N;i++) {\n  ll p;cin>>p;\n\
    \  g[i].push_back(p);\n  g[p].push_back(i);\n}\n\n  HeavyLightDecomposition hld(g);\n\
    \  hld.build();\n\n  for(ll i=0;i<Q;i++) {\n    ll u,v;cin>>u>>v;\n    cout<<hld.lca(u,v)<<endl;\n\
    \  }\n\n}\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../tree/HLD.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n  \nll N,Q;cin>>N>>Q;\n\
    vector<vector<int>> g(N,vector<int> (0));\nfor(ll i=1;i<N;i++) {\n  ll p;cin>>p;\n\
    \  g[i].push_back(p);\n  g[p].push_back(i);\n}\n\n  HeavyLightDecomposition hld(g);\n\
    \  hld.build();\n\n  for(ll i=0;i<Q;i++) {\n    ll u,v;cin>>u>>v;\n    cout<<hld.lca(u,v)<<endl;\n\
    \  }\n\n}\n\n\n"
  dependsOn:
  - tree/HLD.hpp
  isVerificationFile: true
  path: test/HLD.test.cpp
  requiredBy: []
  timestamp: '2024-03-22 12:52:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/HLD.test.cpp
layout: document
redirect_from:
- /verify/test/HLD.test.cpp
- /verify/test/HLD.test.cpp.html
title: test/HLD.test.cpp
---
