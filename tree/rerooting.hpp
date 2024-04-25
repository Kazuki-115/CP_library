#pragma once

#include<bits/stdc++.h>
using namespace std;


/*
使い方
Data : 各頂点が持つもの
T：各辺が持つもの
F1：頂点同士をマージする時のマージの仕方
F2：子から親へと情報が移動するときの変化

*/

template< typename Data, typename T >
struct ReRooting {
 
  struct Node {
    int to, rev;
    Data data;
  };
 
  using F1 = function< T(T, T) >;
  using F2 = function< T(T, Data) >;
 
  vector< vector< Node > > g;
  vector< vector< T > > ldp, rdp;
  vector<T> plus;
  vector< int > lptr, rptr;
  const F1 f1;
  const F2 f2;
  const T ident;
 
  ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident) :
      g(n), ldp(n), rdp(n), lptr(n), rptr(n), plus(n,ident),f1(f1), f2(f2), ident(ident) {}

 void add_plus(vector<T> plus_) {
  plus=plus_;
 }

  void add_edge(int u, int v, const Data &d) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, d});
  }
 
  void add_edge_bi(int u, int v, const Data &d, const Data &e) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, e});
  }
 
 
  T dfs(int idx, int par) {
 
    while(lptr[idx] != par && lptr[idx] < g[idx].size()) {
      auto &e = g[idx][lptr[idx]];
      ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));
      ++lptr[idx];
    }


    while(rptr[idx] != par && rptr[idx] >= 0) {
      auto &e = g[idx][rptr[idx]];
      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), e.data));
      --rptr[idx];
    }

    if(par < 0) return f1(rdp[idx][0],plus[idx]);
    return f1(f1(ldp[idx][par], rdp[idx][par + 1]),plus[idx]);
  }
 
  vector< T > solve() {
    for(int i = 0; i < g.size(); i++) {
      ldp[i].assign(g[i].size() + 1, ident);
      rdp[i].assign(g[i].size() + 1, ident);
      lptr[i] = 0;
      rptr[i] = (int) g[i].size() - 1;
    }
    vector< T > ret;
    for(int i = 0; i < g.size(); i++) {
      ret.push_back(dfs(i, -1));
    }
    return ret;
  }
};
