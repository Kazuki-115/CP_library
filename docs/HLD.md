## function

- `T query(int u, int v, const T &ti, const Q &q, const F &f, bool edge = false)`  
u-v間のパスクエリを返す．  
l,rで左右それぞれのものを合併していく．lは常に深いほうに対応している．  
stack見たいな感じでl,rは手前が浅い方で奥が深い方になるようにデータをマージしていく．  
q,fは非可換演算でも行けるけど，最後にl,rを合併するときにどちらかを反転させる必要がある．

