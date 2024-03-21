#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../tree/HLD.hpp"

#include<bits/stdc++.h>
using namespace std;
using ll =long long;


int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);
  
ll N,Q;cin>>N>>Q;
vector<vector<int>> g(N,vector<int> (0));
for(ll i=1;i<N;i++) {
  ll p;cin>>p;
  g[i].push_back(p);
  g[p].push_back(i);
}

  HeavyLightDecomposition hld(g);
  hld.build();

  for(ll i=0;i<Q;i++) {
    ll u,v;cin>>u>>v;
    cout<<hld.lca(u,v)<<endl;
  }

}


