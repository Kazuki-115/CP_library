#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../tree/tree_diameter.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll =long long;



int main() {
  ll N;cin>>N;
  vector<vector<pair<int,ll>>> vec(N,vector<pair<int,ll>> (0));
  for(ll i=0;i<N-1;i++) {
    ll a,b,c;cin>>a>>b>>c;
    vec[a].push_back(make_pair(b,c));
    vec[b].push_back(make_pair(a,c));
  }


  auto ans=tree_diameter<ll>(vec);

  cout<<ans.first<<" "<<ans.second.size()<<endl;
  for(auto x:ans.second) cout<<x<<" ";
  cout<<endl;
}

