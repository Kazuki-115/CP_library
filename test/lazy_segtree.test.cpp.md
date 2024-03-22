---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segtree.hpp
    title: data_structure/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: math/mint998.hpp
    title: math/mint998.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/lazy_segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n\
    \n\n\n#line 1 \"data_structure/lazy_segtree.hpp\"\n\ntemplate<class Operator>\
    \ class LazySegmentTree {\n    Operator Op;                                  \
    \     \n\tusing typeNode = decltype(Op.unitNode);          \n\tusing typeLazy\
    \ = decltype(Op.unitLazy);\n\tsize_t num;      \n\tsize_t length;            \
    \                       \n\tsize_t height;                                   \n\
    \tvector<typeNode> node;                           \n\tvector<typeLazy> lazy;\
    \                           \n\tvector<pair<size_t,size_t>> range;\npublic:\n\n\
    \t//unit\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const size_t num) : num(num)\
    \ {\n\t\tfor (length = 1,height = 0; length < num; length *= 2, height++);\n\t\
    \tnode.resize(2 * length, Op.unitNode);\n\t\tlazy.resize(2 * length, Op.unitLazy);\n\
    \t\tfor (int i = 0; i < num; ++i) node[i + length] = Op.unitNode;\n\t\tfor (int\
    \ i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \t\trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t// //\u540C\u3058init\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const\
    \ size_t num, const typeNode init) : num(num) {\n\t\tfor (length = 1,height =\
    \ 0; length < num; length *= 2, height++);\n\t\tnode.resize(2 * length, Op.unitNode);\n\
    \t\tlazy.resize(2 * length, Op.unitLazy);\n\t\tfor (int i = 0; i < num; ++i) node[i\
    \ + length] = init;\n\t\tfor (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \t\trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<typeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length < vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Op.unitNode);\n\t\tlazy.resize(2\
    \ * length, Op.unitLazy);\n\t\tfor (int i = 0; i < vec.size(); ++i) node[i + length]\
    \ = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \t\trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k] == Op.unitLazy) return;\n\t\t\
    node[k] = Op.funcMerge(node[k],lazy[k],range[k].second-range[k].first);\n\t\t\
    if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);\n\t\tif(k < length)\
    \ lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);\n\t\tlazy[k] = Op.unitLazy;\n\
    \    }\n\n\n\t//update [a,b)\n    void update(int a, int b, typeLazy x) {\n\t\t\
    int l = a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i)\
    \ propagate(l >> i), propagate(r >> i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\
    \t\t\tif(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;\n\t\t\tif(r&1)\
    \ --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);\n\t\t}\n\t\tl = a + length,\
    \ r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l) {\n\t\t\tif(lazy[l] == Op.unitLazy)\
    \ node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));\n\
    \t\t\tif(lazy[r] == Op.unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].second-range[(r<<1)+0].first),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].second-range[(r<<1)+1].first));\n\
    \t\t}\n    }\n\n\t//get [a,b)\n\ttypeNode get(int a, int b) {\n\t\tint l = a +\
    \ length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\ttypeNode vl = Op.unitNode, vr = Op.unitNode;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],range[l].second-range[l].first)),l++;\n\
    \t\t\tif(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],range[r].second-range[r].first),vr);\n\
    \t\t}\n\t\treturn Op.funcNode(vl,vr);\n\t}\n\n\t//return [0,length]\n\tint PrefixBinarySearch(typeNode\
    \ var) {\n\t\tint l = length, r = 2*length - 1;\n\t\tfor (int i = height; 0 <\
    \ i; --i) propagate(l >> i), propagate(r >> i);\n\t\tif(!Op.funcCheck(node[1],var))\
    \ return num;\n\t\ttypeNode ret = Op.unitNode;\n\t\tsize_t idx = 2;\n\t\tfor(;\
    \ idx < 2*length; idx<<=1){\n\t\t\tif(!Op.funcCheck(Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first));\n\
    \t\t\t\tidx++;\n\t\t\t}\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\t}\n\n\
    \t//range[l,r) return [l,r]\n\tint BinarySearch(size_t l, size_t r, typeNode var)\
    \ {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\tfor\
    \ (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\ttypeNode ret = Op.unitNode;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n\t\t\tif(range[idx].second<=r\
    \ && !Op.funcCheck(Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,Op.funcMerge(node[idx],lazy[idx],range[idx].second-range[idx].first));\n\
    \t\t\t\toff = range[idx++].second;\n\t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\
    \t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n};\n\
    \n#line 3 \"math/mint998.hpp\"\nusing namespace std;\nusing ll =long long;\n\n\
    ll INF=2e18;\n\n\ntemplate<int mod> \nclass modint {\n    long long x;\npublic:\n\
    \    modint(long long x=0) : x((x%mod+mod)%mod) {}\n    modint operator-() const\
    \ { \n      return modint(-x);\n    }\n    modint& operator+=(const modint& a)\
    \ {\n        if ((x += a.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    modint& operator-=(const modint& a) {\n        if ((x += mod-a.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    modint& operator*=(const  modint&\
    \ a) {\n        (x *= a.x) %= mod;\n        return *this;\n    }\n    modint operator+(const\
    \ modint& a) const {\n        modint res(*this);\n        return res+=a;\n   \
    \ }\n    modint operator-(const modint& a) const {\n        modint res(*this);\n\
    \        return res-=a;\n    }\n    modint operator*(const modint& a) const {\n\
    \        modint res(*this);\n        return res*=a;\n    }\n    modint pow(ll\
    \ t) const {\n        if (!t) return 1;\n        modint a = pow(t>>1);\n     \
    \   a *= a;\n        if (t&1) a *= *this;\n        return a;\n    }\n    // for\
    \ prime mod\n    modint inv() const {\n        return pow(mod-2);\n    }\n   \
    \ modint& operator/=(const modint& a) {\n        return (*this) *= a.inv();\n\
    \    }\n    modint operator/(const modint& a) const {\n        modint res(*this);\n\
    \        return res/=a;\n    }\n\n    bool operator==(const modint &a) const {\n\
    \        modint res(*this);\n        return res.x==a.x;\n    }\n\n    bool operator!=(const\
    \ modint &a) const {\n        modint res(*this);\n        return res.x!=a.x;\n\
    \    }\n\n\n    friend ostream& operator<<(ostream& os, const modint& m){\n  \
    \      os << m.x;\n        return os;\n    }\n};\n#line 13 \"test/lazy_segtree.test.cpp\"\
    \n\n\n\nusing mint=modint<998244353>;\n\n\n struct Info {\n    using typeNode=mint;\n\
    \    using typeLazy=pair<mint,mint>;\n\ttypeNode unitNode = 0;\n\ttypeLazy unitLazy\
    \ = make_pair(1,0);\n\ttypeNode funcNode(typeNode l,typeNode r){return l+r;}\n\
    \ttypeLazy funcLazy(typeLazy l,typeLazy r){return make_pair(r.first*l.first,r.first*l.second+r.second);}\n\
    \ttypeNode funcMerge(typeNode l,typeLazy r,int len){return r.first*l+r.second*len;}\n\
    };\n\n\nint main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n\n\nll\
    \ N,Q;cin>>N>>Q;\nvector<mint> a(N);\nfor(ll i=0;i<N;i++) {\n  ll A;cin>>A;\n\
    \  a[i]=A;\n}\n\nLazySegmentTree<Info> seg(a);\n\nfor(ll i=0;i<Q;i++) {\n  ll\
    \ t;cin>>t;\n\n  if(t==0) {\n    ll l,r,b,c;cin>>l>>r>>b>>c;\n    seg.update(l,r,make_pair(b,c));\n\
    \n}\n\n\n  else {\n    ll l,r;cin>>l>>r;\n   cout<<seg.get(l,r)<<endl;\n    \n\
    \  }\n\n\n}\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n\n\
    \n\n\n#include \"../data_structure/lazy_segtree.hpp\"\n#include \"../math/mint998.hpp\"\
    \n\n\n\nusing mint=modint<998244353>;\n\n\n struct Info {\n    using typeNode=mint;\n\
    \    using typeLazy=pair<mint,mint>;\n\ttypeNode unitNode = 0;\n\ttypeLazy unitLazy\
    \ = make_pair(1,0);\n\ttypeNode funcNode(typeNode l,typeNode r){return l+r;}\n\
    \ttypeLazy funcLazy(typeLazy l,typeLazy r){return make_pair(r.first*l.first,r.first*l.second+r.second);}\n\
    \ttypeNode funcMerge(typeNode l,typeLazy r,int len){return r.first*l+r.second*len;}\n\
    };\n\n\nint main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n\n\nll\
    \ N,Q;cin>>N>>Q;\nvector<mint> a(N);\nfor(ll i=0;i<N;i++) {\n  ll A;cin>>A;\n\
    \  a[i]=A;\n}\n\nLazySegmentTree<Info> seg(a);\n\nfor(ll i=0;i<Q;i++) {\n  ll\
    \ t;cin>>t;\n\n  if(t==0) {\n    ll l,r,b,c;cin>>l>>r>>b>>c;\n    seg.update(l,r,make_pair(b,c));\n\
    \n}\n\n\n  else {\n    ll l,r;cin>>l>>r;\n   cout<<seg.get(l,r)<<endl;\n    \n\
    \  }\n\n\n}\n}\n\n"
  dependsOn:
  - data_structure/lazy_segtree.hpp
  - math/mint998.hpp
  isVerificationFile: true
  path: test/lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 14:50:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_segtree.test.cpp
- /verify/test/lazy_segtree.test.cpp.html
title: test/lazy_segtree.test.cpp
---
