#define PROBLEM   "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
#include "../string/rolling_hash.hpp"
using namespace std;

using ll=long long;


int main() {
    string T,P;
    cin>>T>>P;
    rolling_hash ht(T),hp(P);
ll N=T.size(),M=P.size();

    for(ll i=0;i<N;i++) {
        if(i+M-1>=N) break;
        if(ht.hash(i,i+M)==hp.hash(0,M)) cout<<i<<endl;
    }
}




