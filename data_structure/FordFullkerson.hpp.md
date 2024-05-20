---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FordFullkerson.test.cpp
    title: test/FordFullkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/FordFullkerson.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\n\n\n\ntemplate< typename flow_t >\n\
    struct FordFulkerson {\n  struct edge {\n    int to;\n    flow_t cap;\n    int\
    \ rev;\n    bool isrev;\n    int idx;\n  };\n\n  vector< vector< edge > > graph;\n\
    \  vector< int > used;\n  const flow_t INF;\n  int timestamp;\n\n  FordFulkerson(int\
    \ n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {\n    graph.resize(n);\n\
    \    used.assign(n, -1);\n  }\n\n  void add_edge(int from, int to, flow_t cap,\
    \ int idx = -1) {\n    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(),\
    \ false, idx});\n    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size()\
    \ - 1, true, idx});\n  }\n\n  flow_t dfs(int idx, const int t, flow_t flow) {\n\
    \    if(idx == t) return flow;\n    used[idx] = timestamp;\n    for(auto &e :\
    \ graph[idx]) {\n      if(e.cap > 0 && used[e.to] != timestamp) {\n        flow_t\
    \ d = dfs(e.to, t, min(flow, e.cap));\n        if(d > 0) {\n          e.cap -=\
    \ d;\n          graph[e.to][e.rev].cap += d;\n          return d;\n        }\n\
    \      }\n    }\n    return 0;\n  }\n\n  flow_t max_flow(int s, int t) {\n   \
    \ flow_t flow = 0;\n    for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {\n\
    \      flow += f;\n    }\n    return flow;\n  }\n\n  void output() {\n    for(int\
    \ i = 0; i < graph.size(); i++) {\n      for(auto &e : graph[i]) {\n        if(e.isrev)\
    \ continue;\n        auto &rev_e = graph[e.to][e.rev];\n        cout << i << \"\
    ->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \"\
    )\" << endl;\n      }\n    }\n  }\n};\n\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\n\n\n\ntemplate< typename flow_t >\nstruct FordFulkerson {\n  struct edge\
    \ {\n    int to;\n    flow_t cap;\n    int rev;\n    bool isrev;\n    int idx;\n\
    \  };\n\n  vector< vector< edge > > graph;\n  vector< int > used;\n  const flow_t\
    \ INF;\n  int timestamp;\n\n  FordFulkerson(int n) : INF(numeric_limits< flow_t\
    \ >::max()), timestamp(0) {\n    graph.resize(n);\n    used.assign(n, -1);\n \
    \ }\n\n  void add_edge(int from, int to, flow_t cap, int idx = -1) {\n    graph[from].emplace_back((edge)\
    \ {to, cap, (int) graph[to].size(), false, idx});\n    graph[to].emplace_back((edge)\
    \ {from, 0, (int) graph[from].size() - 1, true, idx});\n  }\n\n  flow_t dfs(int\
    \ idx, const int t, flow_t flow) {\n    if(idx == t) return flow;\n    used[idx]\
    \ = timestamp;\n    for(auto &e : graph[idx]) {\n      if(e.cap > 0 && used[e.to]\
    \ != timestamp) {\n        flow_t d = dfs(e.to, t, min(flow, e.cap));\n      \
    \  if(d > 0) {\n          e.cap -= d;\n          graph[e.to][e.rev].cap += d;\n\
    \          return d;\n        }\n      }\n    }\n    return 0;\n  }\n\n  flow_t\
    \ max_flow(int s, int t) {\n    flow_t flow = 0;\n    for(flow_t f; (f = dfs(s,\
    \ t, INF)) > 0; timestamp++) {\n      flow += f;\n    }\n    return flow;\n  }\n\
    \n  void output() {\n    for(int i = 0; i < graph.size(); i++) {\n      for(auto\
    \ &e : graph[i]) {\n        if(e.isrev) continue;\n        auto &rev_e = graph[e.to][e.rev];\n\
    \        cout << i << \"->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" <<\
    \ e.cap + rev_e.cap << \")\" << endl;\n      }\n    }\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/FordFullkerson.hpp
  requiredBy: []
  timestamp: '2024-05-21 00:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FordFullkerson.test.cpp
documentation_of: data_structure/FordFullkerson.hpp
layout: document
redirect_from:
- /library/data_structure/FordFullkerson.hpp
- /library/data_structure/FordFullkerson.hpp.html
title: data_structure/FordFullkerson.hpp
---
