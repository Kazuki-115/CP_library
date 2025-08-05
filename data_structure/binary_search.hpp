#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Binary Search implementation
 * @tparam T Type of elements
 */
template<typename T>
class BinarySearch {
private:
    vector<T> data;

public:
    /**
     * @brief Constructor
     * @param vec Input vector (must be sorted)
     */
    BinarySearch(const vector<T>& vec) : data(vec) {}

    /**
     * @brief Find the first element >= target
     * @param target Target value
     * @return Index of first element >= target, or data.size() if not found
     */
    int lower_bound(T target) const {
        int left = 0, right = data.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    /**
     * @brief Find the first element > target
     * @param target Target value
     * @return Index of first element > target, or data.size() if not found
     */
    int upper_bound(T target) const {
        int left = 0, right = data.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    /**
     * @brief Check if target exists in the array
     * @param target Target value
     * @return true if found, false otherwise
     */
    bool contains(T target) const {
        int idx = lower_bound(target);
        return idx < data.size() && data[idx] == target;
    }
}; 