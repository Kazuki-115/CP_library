---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: data_structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n#line\
    \ 2 \"data_structure/segtree.hpp\"\n\n#line 4 \"data_structure/segtree.hpp\"\n\
    using namespace std;\n\n\ntemplate<typename T>\nclass segtree {\n  public:\n \
    \   int N;//\u8449\u306E\u6570\n    vector<T> data;//\u914D\u5217\n    T unit;//\u5358\
    \u4F4D\u5143\n    function<T(T,T)> op;//\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\
    \u3046\u51E6\u7406\n    function<T(T,T)> up;//\u70B9\u66F4\u65B0\u3067\u4F7F\u3046\
    \u51E6\u7406\n\n    T _query(int a, int b, int k, int l, int r) {\n        if(r\
    \ <= a || b <= l)return unit;\n        if(a <= l && r <= b){\n            return\
    \ data[k];\n        }\n        else{\n            T c1 = _query(a, b, 2 * k +\
    \ 1, l, (l + r) / 2); //\u5DE6\u306E\u5B50\n            T c2 = _query(a, b, 2\
    \ * k + 2, (l + r) / 2, r); //\u5DE6\u306E\u5B50\n            return op(c1, c2);\n\
    \        }\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u30FC\n  \
    \  //_N: \u5FC5\u8981\u30B5\u30A4\u30BA, _unit: \u521D\u671F\u5024\u304B\u3064\
    \u5358\u4F4D\u5143, _op: \u30AF\u30A8\u30EA\u95A2\u6570, _update: \u66F4\u65B0\
    \u95A2\u6570\n    segtree(int _N, T _unit, function<T(T, T)> _op, function<T(T,\
    \ T)> _update) \n        :unit(_unit), op(_op), up(_update){\n        N = 1;\n\
    \        while(N < _N)N *= 2;\n        data.assign(2 * N - 1, unit);\n    }\n\
    \    //i(0-indexed)\u306E\u5024\u306Bupdate\u95A2\u6570\u3092\u9069\u7528\n  \
    \  void update(int i, T x){\n        i += N - 1;\n        data[i] = up(data[i],\
    \ x);\n        while(i > 0){\n            i = (i - 1) / 2;\n            data[i]\
    \ = op(data[i * 2 + 1], data[i * 2 + 2]);\n        }\n    }\n    //[a, b)\u306E\
    \u533A\u9593\u30AF\u30A8\u30EA\u306E\u5B9F\u884C\n    T query(int a, int b){\n\
    \        return _query(a, b, 0, 0, N);\n    }\n    //\u6DFB\u5B57\u3067\u30A2\u30AF\
    \u30BB\u30B9\n    T operator[](int i) {\n        return data[i + N - 1];\n   \
    \ }\n};\n#line 8 \"test/segtree.test.cpp\"\n\n\nint main() {\nll N,Q;cin>>N>>Q;\n\
    vector<ll> a(N);\nfor(ll i=0;i<N;i++) {\n  cin>>a[i];\n}\n\nauto f=[&](ll a,ll\
    \ b) {\n  return a+b;\n};\n\n\nsegtree<ll> seg(N,0,f,f);\nfor(ll i=0;i<N;i++)\
    \ {\n  seg.update(i,a[i]);\n}\n\nfor(ll i=0;i<Q;i++) {\n  ll t;cin>>t;\n  if(t==0)\
    \ {\n    ll p,x;cin>>p>>x;\n    seg.update(p,x);\n  }\n  else {\n    ll l,r;cin>>l>>r;\n\
    \    cout<<seg.query(l,r)<<endl;\n  }\n}\n\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n#include\
    \ \"../data_structure/segtree.hpp\"\n\n\nint main() {\nll N,Q;cin>>N>>Q;\nvector<ll>\
    \ a(N);\nfor(ll i=0;i<N;i++) {\n  cin>>a[i];\n}\n\nauto f=[&](ll a,ll b) {\n \
    \ return a+b;\n};\n\n\nsegtree<ll> seg(N,0,f,f);\nfor(ll i=0;i<N;i++) {\n  seg.update(i,a[i]);\n\
    }\n\nfor(ll i=0;i<Q;i++) {\n  ll t;cin>>t;\n  if(t==0) {\n    ll p,x;cin>>p>>x;\n\
    \    seg.update(p,x);\n  }\n  else {\n    ll l,r;cin>>l>>r;\n    cout<<seg.query(l,r)<<endl;\n\
    \  }\n}\n\n}\n\n"
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/segtree.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 14:50:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segtree.test.cpp
layout: document
redirect_from:
- /verify/test/segtree.test.cpp
- /verify/test/segtree.test.cpp.html
title: test/segtree.test.cpp
---
