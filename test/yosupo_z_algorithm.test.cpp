#define PROBLEM   "https://judge.yosupo.jp/problem/zalgorithm"

#include "../string/z_algorithm.hpp"


#include <bits/stdc++.h>
using namespace std;
using ll=long long;



int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);
 
 string S;cin>>S;
 Z_algorithm z;
 z.build(S);

 for(ll i=0;i<z.size();i++) {
  cout<<z[i]<<" ";
 }
 cout<<endl;
 
}
