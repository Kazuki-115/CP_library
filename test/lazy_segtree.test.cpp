#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"


#include <bits/stdc++.h>
using namespace std;
using ll =long long;




#include "lazy_segtree.hpp"
#include "mint998.hpp"



using mint=modint<998244353>;



 struct Info {
    using typeNode=mint;
    using typeLazy=pair<mint,mint>;
	typeNode unitNode = 0;
	typeLazy unitLazy = make_pair(1,0);
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return make_pair(r.first*l.first,r.first*l.second+r.second);}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r.first*l+r.second*len;}
};


int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);


ll N,Q;cin>>N>>Q;
vector<mint> a(N);
for(ll i=0;i<N;i++) {
  ll A;cin>>A;
  a[i]=A;
}

LazySegmentTree<Info> seg(a);

for(ll i=0;i<Q;i++) {
  ll t;cin>>t;

  if(t==0) {
    ll l,r,b,c;cin>>l>>r>>b>>c;
    seg.update(l,r,make_pair(b,c));

}


  else {
    ll l,r;cin>>l>>r;
   cout<<seg.get(l,r)<<endl;
    
  }


}
}

