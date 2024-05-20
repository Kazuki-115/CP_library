#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../data_structure/dinic.hpp"

#include<bits/stdc++.h>
using namespace std;
using ll=long long;




int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);

ll U,V;cin>>U>>V;
Dinic<ll> g(U);

for(ll i=0;i<V;i++) {
  ll u,v,c;cin>>u>>v>>c;
  g.add_edge(u,v,c);
}

cout<<g.max_flow(0,U-1)<<endl;
}

