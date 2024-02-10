#pragma once
#include <bits/stdc++.h> 
using namespace std;
using ll =long long;

ll INF=2e18;


template<int mod> 
class modint {
    long long x;
public:
    modint(long long x=0) : x((x%mod+mod)%mod) {}
    modint operator-() const { 
      return modint(-x);
    }
    modint& operator+=(const modint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    modint& operator*=(const  modint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    modint operator+(const modint& a) const {
        modint res(*this);
        return res+=a;
    }
    modint operator-(const modint& a) const {
        modint res(*this);
        return res-=a;
    }
    modint operator*(const modint& a) const {
        modint res(*this);
        return res*=a;
    }
    modint pow(ll t) const {
        if (!t) return 1;
        modint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    modint inv() const {
        return pow(mod-2);
    }
    modint& operator/=(const modint& a) {
        return (*this) *= a.inv();
    }
    modint operator/(const modint& a) const {
        modint res(*this);
        return res/=a;
    }

    bool operator==(const modint &a) const {
        modint res(*this);
        return res.x==a.x;
    }

    bool operator!=(const modint &a) const {
        modint res(*this);
        return res.x!=a.x;
    }


    friend ostream& operator<<(ostream& os, const modint& m){
        os << m.x;
        return os;
    }
};
