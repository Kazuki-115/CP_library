 #pragma once

#include<bits/stdc++.h>
using namespace std;


/// オイラーツアー
struct EulerTour{
  vector<int> order;
  vector<pair<int,int>> sita;

  EulerTour(vector<vector<int>>& G, int root=0){
    int n=G.size();
    order.resize(n);
    sita.resize(n);
    int cur=0;

    function<void(int,int)> dfs=[&](int v, int p){
      order[v]=cur;
      cur++;
      for(auto nv: G[v]){
        if(nv==p) continue;
        dfs(nv, v);
      }
      sita[v]=make_pair(order[v],cur-1);
    };
    dfs(root, -1);
  }
};

