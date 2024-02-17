#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"


#include "../tree/rerooting.hpp"
#include "../math/mint998.hpp"


#include <bits/stdc++.h>
using namespace std;
using ll =long long;



using mint=modint<998244353>;

struct Data{
    ll b;
    ll c;
};



int main() {
    ll N;cin>>N;
    vector<ll> a(N);
    for(ll i=0;i<N;i++) {
        cin>>a[i];

    }

vector<pair<mint,mint>> A(N);
for(ll i=0;i<N;i++) {
    A[i]=make_pair(a[i],1);
}

auto f1=[](pair<mint,mint> x,pair<mint,mint> y) {
return make_pair(x.first+y.first,x.second+y.second);
};

auto f2=[](pair<mint,mint> x,Data y) {
    return make_pair(x.first*y.b+x.second*y.c,x.second);
};

ReRooting<Data,pair<mint,mint>> g(N,f1,f2,{0,0});
g.add_plus(A);

for(ll i=0;i<N-1;i++) {
    ll u,v,b,c;cin>>u>>v>>b>>c;
    g.add_edge(u,v,{b,c});
}

auto ans=g.solve();

for(auto x:ans) {
    cout<<x.first<<endl;
}
}