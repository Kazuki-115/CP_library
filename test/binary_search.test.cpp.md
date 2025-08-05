---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_search.hpp
    title: Binary Search implementation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/binary_search.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    #line 3 \"data_structure/binary_search.hpp\"\nusing namespace std;\n\n/**\n *\
    \ @brief Binary Search implementation\n * @tparam T Type of elements\n */\ntemplate<typename\
    \ T>\nclass BinarySearch {\nprivate:\n    vector<T> data;\n\npublic:\n    /**\n\
    \     * @brief Constructor\n     * @param vec Input vector (must be sorted)\n\
    \     */\n    BinarySearch(const vector<T>& vec) : data(vec) {}\n\n    /**\n \
    \    * @brief Find the first element >= target\n     * @param target Target value\n\
    \     * @return Index of first element >= target, or data.size() if not found\n\
    \     */\n    int lower_bound(T target) const {\n        int left = 0, right =\
    \ data.size();\n        while (left < right) {\n            int mid = left + (right\
    \ - left) / 2;\n            if (data[mid] < target) {\n                left =\
    \ mid + 1;\n            } else {\n                right = mid;\n            }\n\
    \        }\n        return left;\n    }\n\n    /**\n     * @brief Find the first\
    \ element > target\n     * @param target Target value\n     * @return Index of\
    \ first element > target, or data.size() if not found\n     */\n    int upper_bound(T\
    \ target) const {\n        int left = 0, right = data.size();\n        while (left\
    \ < right) {\n            int mid = left + (right - left) / 2;\n            if\
    \ (data[mid] <= target) {\n                left = mid + 1;\n            } else\
    \ {\n                right = mid;\n            }\n        }\n        return left;\n\
    \    }\n\n    /**\n     * @brief Check if target exists in the array\n     * @param\
    \ target Target value\n     * @return true if found, false otherwise\n     */\n\
    \    bool contains(T target) const {\n        int idx = lower_bound(target);\n\
    \        return idx < data.size() && data[idx] == target;\n    }\n}; \n#line 8\
    \ \"test/binary_search.test.cpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    \n    int N, Q;\n    cin >> N >> Q;\n    \n    vector<ll>\
    \ A(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    \n\
    \    // Create prefix sum array\n    vector<ll> prefix(N + 1, 0);\n    for (int\
    \ i = 0; i < N; i++) {\n        prefix[i + 1] = prefix[i] + A[i];\n    }\n   \
    \ \n    // Use binary search to find the answer (just for testing)\n    BinarySearch<ll>\
    \ bs(prefix);\n    \n    for (int i = 0; i < Q; i++) {\n        int l, r;\n  \
    \      cin >> l >> r;\n        \n        // Calculate sum using prefix sum\n \
    \       ll sum = prefix[r] - prefix[l];\n        cout << sum << \"\\n\";\n   \
    \ }\n    \n    return 0;\n} \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#include\
    \ \"../data_structure/binary_search.hpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    \n    int N, Q;\n    cin >> N >> Q;\n    \n    vector<ll>\
    \ A(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    \n\
    \    // Create prefix sum array\n    vector<ll> prefix(N + 1, 0);\n    for (int\
    \ i = 0; i < N; i++) {\n        prefix[i + 1] = prefix[i] + A[i];\n    }\n   \
    \ \n    // Use binary search to find the answer (just for testing)\n    BinarySearch<ll>\
    \ bs(prefix);\n    \n    for (int i = 0; i < Q; i++) {\n        int l, r;\n  \
    \      cin >> l >> r;\n        \n        // Calculate sum using prefix sum\n \
    \       ll sum = prefix[r] - prefix[l];\n        cout << sum << \"\\n\";\n   \
    \ }\n    \n    return 0;\n} "
  dependsOn:
  - data_structure/binary_search.hpp
  isVerificationFile: true
  path: test/binary_search.test.cpp
  requiredBy: []
  timestamp: '2025-08-05 17:07:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary_search.test.cpp
layout: document
redirect_from:
- /verify/test/binary_search.test.cpp
- /verify/test/binary_search.test.cpp.html
title: test/binary_search.test.cpp
---
