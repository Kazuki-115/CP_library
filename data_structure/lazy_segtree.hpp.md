---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segtree.test.cpp
    title: test/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/lazy_segtree.hpp\"\n\ntemplate<class Operator>\
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
    \n"
  code: "\ntemplate<class Operator> class LazySegmentTree {\n    Operator Op;    \
    \                                   \n\tusing typeNode = decltype(Op.unitNode);\
    \          \n\tusing typeLazy = decltype(Op.unitLazy);\n\tsize_t num;      \n\t\
    size_t length;                                   \n\tsize_t height;          \
    \                         \n\tvector<typeNode> node;                         \
    \  \n\tvector<typeLazy> lazy;                           \n\tvector<pair<size_t,size_t>>\
    \ range;\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const\
    \ size_t num) : num(num) {\n\t\tfor (length = 1,height = 0; length < num; length\
    \ *= 2, height++);\n\t\tnode.resize(2 * length, Op.unitNode);\n\t\tlazy.resize(2\
    \ * length, Op.unitLazy);\n\t\tfor (int i = 0; i < num; ++i) node[i + length]\
    \ = Op.unitNode;\n\t\tfor (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
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
    \n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2024-02-10 14:37:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segtree.test.cpp
documentation_of: data_structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segtree.hpp
- /library/data_structure/lazy_segtree.hpp.html
title: data_structure/lazy_segtree.hpp
---
