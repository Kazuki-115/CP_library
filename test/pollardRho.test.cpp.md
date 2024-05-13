---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/PollardRho.hpp
    title: math/PollardRho.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/pollardRho.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n#define\
    \ all(v) v.begin(),v.end()\n #define rep(i,a,b) for(int i=a;i<b;i++)\n#define\
    \ rrep(i,a,b) for(int i=a;i>=b;i--)\n\n#line 3 \"math/PollardRho.hpp\"\nusing\
    \ namespace std;\nusing ll =long long;\n\n \n  namespace PollardRho {\n    mt19937\
    \ rnd(chrono::steady_clock::now().time_since_epoch().count());\n    const int\
    \ P = 1e6 + 9;\n    ll seq[P];\n    int primes[P], spf[P];\n    inline ll add_mod(ll\
    \ x, ll y, ll m) {\n      return (x += y) < m ? x : x - m;\n    }\n    inline\
    \ ll mul_mod(ll x, ll y, ll m) {\n      ll res = __int128(x) * y % m;\n      return\
    \ res;\n      // ll res = x * y - (ll)((long double)x * y / m + 0.5) * m;\n  \
    \    // return res < 0 ? res + m : res;\n    }\n    inline ll pow_mod(ll x, ll\
    \ n, ll m) {\n      ll res = 1 % m;\n      for (; n; n >>= 1) {\n        if (n\
    \ & 1) res = mul_mod(res, x, m);\n        x = mul_mod(x, x, m);\n      }\n   \
    \   return res;\n    }\n    // O(it * (logn)^3), it = number of rounds performed\n\
    \    inline bool miller_rabin(ll n) {\n      if (n <= 2 || (n & 1 ^ 1)) return\
    \ (n == 2);\n      if (n < P) return spf[n] == n;\n      ll c, d, s = 0, r = n\
    \ - 1;\n      for (; !(r & 1); r >>= 1, s++) {}\n      // each iteration is a\
    \ round\n      for (int i = 0; primes[i] < n && primes[i] < 32; i++) {\n     \
    \   c = pow_mod(primes[i], r, n);\n        for (int j = 0; j < s; j++) {\n   \
    \       d = mul_mod(c, c, n);\n          if (d == 1 && c != 1 && c != (n - 1))\
    \ return false;\n          c = d;\n        }\n        if (c != 1) return false;\n\
    \      }\n      return true;\n    }\n    void init() {\n      int cnt = 0;\n \
    \     for (int i = 2; i < P; i++) {\n        if (!spf[i]) primes[cnt++] = spf[i]\
    \ = i;\n        for (int j = 0, k; (k = i * primes[j]) < P; j++) {\n         \
    \ spf[k] = primes[j];\n          if (spf[i] == spf[k]) break;\n        }\n   \
    \   }\n    }\n    // returns O(n^(1/4))\n    ll pollard_rho(ll n) {\n      while\
    \ (1) {\n        ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;\n  \
    \      ll *px = seq, *py = seq;\n        while (1) {\n          *py++ = y = add_mod(mul_mod(y,\
    \ y, n), c, n);\n          *py++ = y = add_mod(mul_mod(y, y, n), c, n);\n    \
    \      if ((x = *px++) == y) break;\n          v = u;\n          u = mul_mod(u,\
    \ abs(y - x), n);\n          if (!u) return __gcd(v, n);\n          if (++t ==\
    \ 32) {\n            t = 0;\n            if ((u = __gcd(u, n)) > 1 && u < n) return\
    \ u;\n          }\n        }\n        if (t && (u = __gcd(u, n)) > 1 && u < n)\
    \ return u;\n      }\n    }\n    vector<ll> factorize(ll n) {\n      if (n ==\
    \ 1) return vector <ll>();\n      if (miller_rabin(n)) return vector<ll> {n};\n\
    \      vector <ll> v, w;\n      while (n > 1 && n < P) {\n        v.push_back(spf[n]);\n\
    \        n /= spf[n];\n      }\n      if (n >= P) {\n        ll x = pollard_rho(n);\n\
    \        v = factorize(x);\n        w = factorize(n / x);\n        v.insert(v.end(),\
    \ w.begin(), w.end());\n      }\n      return v;\n    }\n  }\n \n#line 12 \"test/pollardRho.test.cpp\"\
    \n\n\n\n\n\n\n\nint main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \nll Q;cin>>Q;\n\nPollardRho::init();\n\nfor(ll i=0;i<Q;i++) {\n  ll a;cin>>a;\n\
    \  auto ans=PollardRho::factorize(a);\n  sort(all(ans));\n  \n\n  cout<<ans.size()<<\"\
    \ \";\n  for(auto x:ans) cout<<x<<\" \";\n  cout<<endl;\n}\n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll =long long;\n#define all(v)\
    \ v.begin(),v.end()\n #define rep(i,a,b) for(int i=a;i<b;i++)\n#define rrep(i,a,b)\
    \ for(int i=a;i>=b;i--)\n\n#include \"../math/PollardRho.hpp\"\n\n\n\n\n\n\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n  cin.tie(0);\n\nll Q;cin>>Q;\n\
    \nPollardRho::init();\n\nfor(ll i=0;i<Q;i++) {\n  ll a;cin>>a;\n  auto ans=PollardRho::factorize(a);\n\
    \  sort(all(ans));\n  \n\n  cout<<ans.size()<<\" \";\n  for(auto x:ans) cout<<x<<\"\
    \ \";\n  cout<<endl;\n}\n}\n\n\n\n\n\n"
  dependsOn:
  - math/PollardRho.hpp
  isVerificationFile: true
  path: test/pollardRho.test.cpp
  requiredBy: []
  timestamp: '2024-05-13 19:34:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/pollardRho.test.cpp
layout: document
redirect_from:
- /verify/test/pollardRho.test.cpp
- /verify/test/pollardRho.test.cpp.html
title: test/pollardRho.test.cpp
---
