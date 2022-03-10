template<class T> struct LazySeg {
    int sz = 1;
    vector<T> t, lz;
    const T BASE = -INF;
    T comb(T a, T b) { return max(a, b); }

    void init(int n) {
        while (sz < n) sz <<= 1;
        t.assign(2*sz, 0), lz.assign(2*sz, 0);
    }
    void push(int v, int l, int r) {
        t[v] += lz[v];
        if (l != r)
            lz[v * 2] += lz[v],
            lz[v*2+1] += lz[v];
        lz[v] = 0;
    }
    void update(int ql, int qr, T x) { update(ql, qr, x, 1, 0, sz-1); }
    void update(int ql, int qr, T x, int v, int l, int r) {
        push(v, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && qr >= r) {
            lz[v] += x;
            return void( push(v, l, r) );
        }
        int m = (l+r)/2;
        update(ql, qr, x, v*2, l, m);
        update(ql, qr, x, v*2+1, m+1, r);
        t[v] = comb( t[v*2], t[v*2+1] );
    }
    T query(int ql, int qr) { return query(ql, qr, 1, 0, sz-1); }
    T query(int ql, int qr, int v, int l, int r) {
        push(v, l, r);
        if (ql > r || qr < l) return BASE;
        if (ql <= l && qr >= r) return t[v];
        int m = (l+r)/2;
        T zl = query(ql, qr, v*2, l, m);
        T zr = query(ql, qr, v*2+1, m+1, r);
        return comb(zl, zr);
    }
};



struct SegTree {
	struct node{
		ll val;
		ll lzAdd;
		ll lzSet;
		node(){};
	}tree[maxN<<2];

	#define lc p<<1
	#define rc (p<<1)+1

	inline void pushup(int p){
		tree[p].val = tree[lc].val + tree[rc].val;
		return;
	}

	void pushdown(int p, int l, int mid, int r){
		//lazy: range set
		if(tree[p].lzSet != 0){
			tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
			tree[lc].val = (mid-l+1) * tree[p].lzSet;
			tree[rc].val = (r-mid) * tree[p].lzSet;
			tree[lc].lzAdd = tree[rc].lzAdd = 0;
			tree[p].lzSet = 0;
		}
		else if(tree[p].lzAdd != 0){ //lazy: range add
			if(tree[lc].lzSet == 0)tree[lc].lzAdd += tree[p].lzAdd;
			else {
				tree[lc].lzSet += tree[p].lzAdd;
				tree[lc].lzAdd = 0;
			}
			if(tree[rc].lzSet == 0)tree[rc].lzAdd += tree[p].lzAdd;
			else{
				tree[rc].lzSet += tree[p].lzAdd;
				tree[rc].lzAdd = 0;
			}
			tree[lc].val += (mid-l+1) * tree[p].lzAdd;
			tree[rc].val += (r-mid) * tree[p].lzAdd;
			tree[p].lzAdd = 0;
		}
		return;
	}

	void build(int p, int l, int r){
		tree[p].lzAdd = tree[p].lzSet = 0;
		if(l == r){
			tree[p].val = a[l];
			return;
		}
		int mid = (l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(p);
		return;
	}
	void add(ll dx, int L, int R) { add(1,1,N,L,R,dx); }
	void add(int p, int l, int r, int a, int b, ll val){
		if(a > r || b < l)return;
		if(a <= l && r <= b){
			tree[p].val += (r-l+1) * val;
			if(tree[p].lzSet == 0)tree[p].lzAdd += val;
			else tree[p].lzSet += val;
			return;
		}
		int mid = (l+r)>>1;
		pushdown(p,l,mid,r);
		add(lc,l,mid,a,b,val);
		add(rc,mid+1,r,a,b,val);
		pushup(p);
		return;
	}
	void set(ll x, int L, int R) { set(1,1,N,L,R,x); }
	void set(int p, int l, int r, int a, int b, ll val){
		if(a > r || b < l)return;
		if(a <= l && r <= b){
			tree[p].val = (r-l+1) * val;
			tree[p].lzAdd = 0;
			tree[p].lzSet = val;
			return;
		}
		int mid = (l+r)>>1;
		pushdown(p,l,mid,r);
		set(lc,l,mid,a,b,val);
		set(rc,mid+1,r,a,b,val);
		pushup(p);
		return;
	}
	ll query(int L, int R) { return query(1,1,N,L,R); }
	ll query(int p, int l, int r, int a, int b){
		if(a > r || b < l)return 0;
		if(a <= l && r <= b)return tree[p].val;
		int mid = (l+r)>>1;
		pushdown(p,l,mid,r);
		return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);
	}
};
