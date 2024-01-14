#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h> 
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 #define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

ll INF=2e18;

const int mod = 998244353;

class mint {
public:
    long long x;
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    bool operator==(const mint &a) const {
      mint res(*this);
      return res.x==a.x;
    }

    bool operator!=(const mint &a) const {
      mint res(*this);
      return res.x!=a.x;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};


template<class Operator> class LazySegmentTree {
    Operator Op;                                       
	using typeNode = decltype(Op.unitNode);          
	using typeLazy = decltype(Op.unitLazy);
	size_t num;      
	size_t length;                                   
	size_t height;                                   
	vector<typeNode> node;                           
	vector<typeLazy> lazy;                           
	vector<pair<size_t,size_t>> range;
public:

	//vectorで初期化
	LazySegmentTree(const vector<typeNode>& vec) : num(vec.size()) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	void propagate(int k) {
		if(lazy[k] == Op.unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],range[k].second-range[k].first);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Op.unitLazy;
    }


	//update [a,b)
    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			 node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));
			 node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].second-range[(r<<1)+0].first),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].second-range[(r<<1)+1].first));
		}
    }

	//get [a,b)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = Op.unitNode, vr = Op.unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],range[l].second-range[l].first)),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],range[r].second-range[r].first),vr);
		}
		return Op.funcNode(vl,vr);
	}

};


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


