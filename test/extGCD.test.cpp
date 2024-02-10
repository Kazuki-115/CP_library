#define PROBLEM   "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja"
#include "../math/extGCD.hpp"

#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    ll a,b;cin>>a>>b;
    
auto p=extgcd(a,b);
cout<<p.first<<" "<<p.second<<endl;
}

