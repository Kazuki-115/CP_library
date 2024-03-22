---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint998.hpp
    title: math/mint998.hpp
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: tree/rerooting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/rerooting.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n\n#line 2 \"tree/rerooting.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
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
    \ }\n    return ret;\n  }\n};\n#line 3 \"math/mint998.hpp\"\nusing namespace std;\n\
    using ll =long long;\n\nll INF=2e18;\n\n\ntemplate<int mod> \nclass modint {\n\
    \    long long x;\npublic:\n    modint(long long x=0) : x((x%mod+mod)%mod) {}\n\
    \    modint operator-() const { \n      return modint(-x);\n    }\n    modint&\
    \ operator+=(const modint& a) {\n        if ((x += a.x) >= mod) x -= mod;\n  \
    \      return *this;\n    }\n    modint& operator-=(const modint& a) {\n     \
    \   if ((x += mod-a.x) >= mod) x -= mod;\n        return *this;\n    }\n    modint&\
    \ operator*=(const  modint& a) {\n        (x *= a.x) %= mod;\n        return *this;\n\
    \    }\n    modint operator+(const modint& a) const {\n        modint res(*this);\n\
    \        return res+=a;\n    }\n    modint operator-(const modint& a) const {\n\
    \        modint res(*this);\n        return res-=a;\n    }\n    modint operator*(const\
    \ modint& a) const {\n        modint res(*this);\n        return res*=a;\n   \
    \ }\n    modint pow(ll t) const {\n        if (!t) return 1;\n        modint a\
    \ = pow(t>>1);\n        a *= a;\n        if (t&1) a *= *this;\n        return\
    \ a;\n    }\n    // for prime mod\n    modint inv() const {\n        return pow(mod-2);\n\
    \    }\n    modint& operator/=(const modint& a) {\n        return (*this) *= a.inv();\n\
    \    }\n    modint operator/(const modint& a) const {\n        modint res(*this);\n\
    \        return res/=a;\n    }\n\n    bool operator==(const modint &a) const {\n\
    \        modint res(*this);\n        return res.x==a.x;\n    }\n\n    bool operator!=(const\
    \ modint &a) const {\n        modint res(*this);\n        return res.x!=a.x;\n\
    \    }\n\n\n    friend ostream& operator<<(ostream& os, const modint& m){\n  \
    \      os << m.x;\n        return os;\n    }\n};\n#line 6 \"test/rerooting.test.cpp\"\
    \n\n\n#line 9 \"test/rerooting.test.cpp\"\nusing namespace std;\nusing ll =long\
    \ long;\n\n\n\nusing mint=modint<998244353>;\n\nstruct Data{\n    ll b;\n    ll\
    \ c;\n};\n\n\n\nint main() {\n    ll N;cin>>N;\n    vector<ll> a(N);\n    for(ll\
    \ i=0;i<N;i++) {\n        cin>>a[i];\n\n    }\n\nvector<pair<mint,mint>> A(N);\n\
    for(ll i=0;i<N;i++) {\n    A[i]=make_pair(a[i],1);\n}\n\nauto f1=[](pair<mint,mint>\
    \ x,pair<mint,mint> y) {\nreturn make_pair(x.first+y.first,x.second+y.second);\n\
    };\n\nauto f2=[](pair<mint,mint> x,Data y) {\n    return make_pair(x.first*y.b+x.second*y.c,x.second);\n\
    };\n\nReRooting<Data,pair<mint,mint>> g(N,f1,f2,{0,0});\ng.add_plus(A);\n\nfor(ll\
    \ i=0;i<N-1;i++) {\n    ll u,v,b,c;cin>>u>>v>>b>>c;\n    g.add_edge(u,v,{b,c});\n\
    }\n\nauto ans=g.solve();\n\nfor(auto x:ans) {\n    cout<<x.first<<endl;\n}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n\n#include \"../tree/rerooting.hpp\"\n#include \"../math/mint998.hpp\"\n\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n\n\n\
    using mint=modint<998244353>;\n\nstruct Data{\n    ll b;\n    ll c;\n};\n\n\n\n\
    int main() {\n    ll N;cin>>N;\n    vector<ll> a(N);\n    for(ll i=0;i<N;i++)\
    \ {\n        cin>>a[i];\n\n    }\n\nvector<pair<mint,mint>> A(N);\nfor(ll i=0;i<N;i++)\
    \ {\n    A[i]=make_pair(a[i],1);\n}\n\nauto f1=[](pair<mint,mint> x,pair<mint,mint>\
    \ y) {\nreturn make_pair(x.first+y.first,x.second+y.second);\n};\n\nauto f2=[](pair<mint,mint>\
    \ x,Data y) {\n    return make_pair(x.first*y.b+x.second*y.c,x.second);\n};\n\n\
    ReRooting<Data,pair<mint,mint>> g(N,f1,f2,{0,0});\ng.add_plus(A);\n\nfor(ll i=0;i<N-1;i++)\
    \ {\n    ll u,v,b,c;cin>>u>>v>>b>>c;\n    g.add_edge(u,v,{b,c});\n}\n\nauto ans=g.solve();\n\
    \nfor(auto x:ans) {\n    cout<<x.first<<endl;\n}\n}"
  dependsOn:
  - tree/rerooting.hpp
  - math/mint998.hpp
  isVerificationFile: true
  path: test/rerooting.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 16:46:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/rerooting.test.cpp
- /verify/test/rerooting.test.cpp.html
title: test/rerooting.test.cpp
---
