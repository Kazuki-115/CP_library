#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;
using ll =long long;

#include "../string/suffix_array.hpp"


int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);
  
  string S;cin>>S;
  SuffixArray sa(S);
  for(ll i=0;i<S.size();i++) {
    cout<<sa.SA[i]<<" ";
  }
  cout<<endl;
}

