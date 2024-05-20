---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/FordFullkerson.hpp
    title: data_structure/FordFullkerson.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/FordFullkerson.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#line 2 \"data_structure/FordFullkerson.hpp\"\n\n\ntemplate< typename flow_t\
    \ >\nstruct FordFulkerson {\n  struct edge {\n    int to;\n    flow_t cap;\n \
    \   int rev;\n    bool isrev;\n    int idx;\n  };\n\n  vector< vector< edge >\
    \ > graph;\n  vector< int > used;\n  const flow_t INF;\n  int timestamp;\n\n \
    \ FordFulkerson(int n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {\n\
    \    graph.resize(n);\n    used.assign(n, -1);\n  }\n\n  void add_edge(int from,\
    \ int to, flow_t cap, int idx = -1) {\n    graph[from].emplace_back((edge) {to,\
    \ cap, (int) graph[to].size(), false, idx});\n    graph[to].emplace_back((edge)\
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
    \ e.cap + rev_e.cap << \")\" << endl;\n      }\n    }\n  }\n};\n\n#line 4 \"test/FordFullkerson.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\n\n\n\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n\nll U,V;cin>>U>>V;\n\
    FordFulkerson<ll> g(U);\n\nfor(ll i=0;i<V;i++) {\n  ll u,v,c;cin>>u>>v>>c;\n \
    \ g.add_edge(u,v,c);\n}\n\ncout<<g.max_flow(0,U-1)<<endl;\n}\n\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../data_structure/FordFullkerson.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\n\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n\nll U,V;cin>>U>>V;\nFordFulkerson<ll> g(U);\n\nfor(ll i=0;i<V;i++)\
    \ {\n  ll u,v,c;cin>>u>>v>>c;\n  g.add_edge(u,v,c);\n}\n\ncout<<g.max_flow(0,U-1)<<endl;\n\
    }\n\n"
  dependsOn:
  - data_structure/FordFullkerson.hpp
  isVerificationFile: true
  path: test/FordFullkerson.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 00:10:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/FordFullkerson.test.cpp
layout: document
redirect_from:
- /verify/test/FordFullkerson.test.cpp
- /verify/test/FordFullkerson.test.cpp.html
title: test/FordFullkerson.test.cpp
---
