
#pragma once


template<typename T>
class segtree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    T unit;//単位元
    function<T(T,T)> op;//区間クエリで使う処理
    function<T(T,T)> up;//点更新で使う処理

    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l)return unit;
        if(a <= l && r <= b){
            return data[k];
        }
        else{
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); //左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); //左の子
            return op(c1, c2);
        }
    }
    //コンストラクター
    //_N: 必要サイズ, _unit: 初期値かつ単位元, _op: クエリ関数, _update: 更新関数
    segtree(int _N, T _unit, function<T(T, T)> _op, function<T(T, T)> _update) 
        :unit(_unit), op(_op), up(_update){
        N = 1;
        while(N < _N)N *= 2;
        data.assign(2 * N - 1, unit);
    }
    //i(0-indexed)の値にupdate関数を適用
    void update(int i, T x){
        i += N - 1;
        data[i] = up(data[i], x);
        while(i > 0){
            i = (i - 1) / 2;
            data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};
