#define PROBLEM "https://judge.yosupo.jp/problem/factorize"


#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 #define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

#include "../math/PollardRho.hpp"







int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);

ll Q;cin>>Q;

PollardRho::init();

for(ll i=0;i<Q;i++) {
  ll a;cin>>a;
  auto ans=PollardRho::factorize(a);
  sort(all(ans));
  

  cout<<ans.size()<<" ";
  for(auto x:ans) cout<<x<<" ";
  cout<<endl;
}
}





