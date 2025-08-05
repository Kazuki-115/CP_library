#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../data_structure/binary_search.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Create prefix sum array
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + A[i];
    }
    
    // Use binary search to find the answer (just for testing)
    BinarySearch<ll> bs(prefix);
    
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        
        // Calculate sum using prefix sum
        ll sum = prefix[r] - prefix[l];
        cout << sum << "\n";
    }
    
    return 0;
} 