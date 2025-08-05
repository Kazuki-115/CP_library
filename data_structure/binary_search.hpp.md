---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary_search.test.cpp
    title: test/binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Search implementation
    links: []
  bundledCode: "#line 2 \"data_structure/binary_search.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @brief Binary Search implementation\n * @tparam\
    \ T Type of elements\n */\ntemplate<typename T>\nclass BinarySearch {\nprivate:\n\
    \    vector<T> data;\n\npublic:\n    /**\n     * @brief Constructor\n     * @param\
    \ vec Input vector (must be sorted)\n     */\n    BinarySearch(const vector<T>&\
    \ vec) : data(vec) {}\n\n    /**\n     * @brief Find the first element >= target\n\
    \     * @param target Target value\n     * @return Index of first element >= target,\
    \ or data.size() if not found\n     */\n    int lower_bound(T target) const {\n\
    \        int left = 0, right = data.size();\n        while (left < right) {\n\
    \            int mid = left + (right - left) / 2;\n            if (data[mid] <\
    \ target) {\n                left = mid + 1;\n            } else {\n         \
    \       right = mid;\n            }\n        }\n        return left;\n    }\n\n\
    \    /**\n     * @brief Find the first element > target\n     * @param target\
    \ Target value\n     * @return Index of first element > target, or data.size()\
    \ if not found\n     */\n    int upper_bound(T target) const {\n        int left\
    \ = 0, right = data.size();\n        while (left < right) {\n            int mid\
    \ = left + (right - left) / 2;\n            if (data[mid] <= target) {\n     \
    \           left = mid + 1;\n            } else {\n                right = mid;\n\
    \            }\n        }\n        return left;\n    }\n\n    /**\n     * @brief\
    \ Check if target exists in the array\n     * @param target Target value\n   \
    \  * @return true if found, false otherwise\n     */\n    bool contains(T target)\
    \ const {\n        int idx = lower_bound(target);\n        return idx < data.size()\
    \ && data[idx] == target;\n    }\n}; \n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief\
    \ Binary Search implementation\n * @tparam T Type of elements\n */\ntemplate<typename\
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
    \        return idx < data.size() && data[idx] == target;\n    }\n}; "
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_search.hpp
  requiredBy: []
  timestamp: '2025-08-05 17:07:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary_search.test.cpp
documentation_of: data_structure/binary_search.hpp
layout: document
redirect_from:
- /library/data_structure/binary_search.hpp
- /library/data_structure/binary_search.hpp.html
title: Binary Search implementation
---
