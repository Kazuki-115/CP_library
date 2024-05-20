---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dinic.hpp
    title: data_structure/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/dinic.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#line 2 \"data_structure/dinic.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\n\n\ntemplate< typename flow_t >\nstruct Dinic {\n\
    \  const flow_t INF;\n\n  struct edge {\n    int to;\n    flow_t cap;\n    int\
    \ rev;\n    bool isrev;\n    int idx;\n  };\n\n  vector< vector< edge > > graph;\n\
    \  vector< int > min_cost, iter;\n\n  Dinic(int V) : INF(numeric_limits< flow_t\
    \ >::max()), graph(V) {}\n\n  void add_edge(int from, int to, flow_t cap, int\
    \ idx = -1) {\n    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(),\
    \ false, idx});\n    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size()\
    \ - 1, true, idx});\n  }\n\n  bool bfs(int s, int t) {\n    min_cost.assign(graph.size(),\
    \ -1);\n    queue< int > que;\n    min_cost[s] = 0;\n    que.push(s);\n    while(!que.empty()\
    \ && min_cost[t] == -1) {\n      int p = que.front();\n      que.pop();\n    \
    \  for(auto &e : graph[p]) {\n        if(e.cap > 0 && min_cost[e.to] == -1) {\n\
    \          min_cost[e.to] = min_cost[p] + 1;\n          que.push(e.to);\n    \
    \    }\n      }\n    }\n    return min_cost[t] != -1;\n  }\n\n  flow_t dfs(int\
    \ idx, const int t, flow_t flow) {\n    if(idx == t) return flow;\n    for(int\
    \ &i = iter[idx]; i < graph[idx].size(); i++) {\n      edge &e = graph[idx][i];\n\
    \      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {\n        flow_t d = dfs(e.to,\
    \ t, min(flow, e.cap));\n        if(d > 0) {\n          e.cap -= d;\n        \
    \  graph[e.to][e.rev].cap += d;\n          return d;\n        }\n      }\n   \
    \ }\n    return 0;\n  }\n\n  flow_t max_flow(int s, int t) {\n    flow_t flow\
    \ = 0;\n    while(bfs(s, t)) {\n      iter.assign(graph.size(), 0);\n      flow_t\
    \ f = 0;\n      while((f = dfs(s, t, INF)) > 0) flow += f;\n    }\n    return\
    \ flow;\n  }\n\n  void output() {\n    for(int i = 0; i < graph.size(); i++) {\n\
    \      for(auto &e : graph[i]) {\n        if(e.isrev) continue;\n        auto\
    \ &rev_e = graph[e.to][e.rev];\n        cout << i << \"->\" << e.to << \" (flow:\
    \ \" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \")\" << endl;\n      }\n \
    \   }\n  }\n};\n#line 4 \"test/dinic.test.cpp\"\n\n#line 6 \"test/dinic.test.cpp\"\
    \nusing namespace std;\nusing ll=long long;\n\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n\nll U,V;cin>>U>>V;\nDinic<ll> g(U);\n\nfor(ll i=0;i<V;i++) {\n\
    \  ll u,v,c;cin>>u>>v>>c;\n  g.add_edge(u,v,c);\n}\n\ncout<<g.max_flow(0,U-1)<<endl;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../data_structure/dinic.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll=long long;\n\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n\nll U,V;cin>>U>>V;\nDinic<ll> g(U);\n\nfor(ll i=0;i<V;i++) {\n\
    \  ll u,v,c;cin>>u>>v>>c;\n  g.add_edge(u,v,c);\n}\n\ncout<<g.max_flow(0,U-1)<<endl;\n\
    }\n\n"
  dependsOn:
  - data_structure/dinic.hpp
  isVerificationFile: true
  path: test/dinic.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 00:19:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dinic.test.cpp
layout: document
redirect_from:
- /verify/test/dinic.test.cpp
- /verify/test/dinic.test.cpp.html
title: test/dinic.test.cpp
---
