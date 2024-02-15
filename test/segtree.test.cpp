#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;
using ll =long long;

#include "../data_structure/segtree.hpp"


int main() {
ll N,Q;cin>>N>>Q;
vector<ll> a(N);
for(ll i=0;i<N;i++) {
  cin>>a[i];
}

auto f=[&](ll a,ll b) {
  return a+b;
};


segtree<ll> seg(N,0,f,f);
for(ll i=0;i<N;i++) {
  seg.update(i,a[i]);
}

for(ll i=0;i<Q;i++) {
  ll t;cin>>t;
  if(t==0) {
    ll p,x;cin>>p>>x;
    seg.update(p,x);
  }
  else {
    ll l,r;cin>>l>>r;
    cout<<seg.query(l,r)<<endl;
  }
}

}

