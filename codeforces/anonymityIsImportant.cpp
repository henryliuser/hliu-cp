#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;
const int INF = 1e8;

int N, Q;
SegTree seg;
set<pi> spec;
int t, l, r, x;

struct SegTree {
    struct node{
        ll val;
        ll lzAdd;
        ll lzSet;
        node(){};
    };
    vector<node> tree;

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
    void build(vector<int> &a) { build(1,1,N,a); }
    void build(int p, int l, int r, vector<int> &a){
        tree[p].lzAdd = tree[p].lzSet = 0;
        if(l == r){
            tree[p].val = a[l];
            return;
        }
        int mid = (l+r)>>1;
        build(lc,l,mid,a);
        build(rc,mid+1,r,a);
        pushup(p);
        return;
    }
    void add(ll dx, int L, int R) { add(1,1,N,L,R,dx); }
    void add(int p, int l, int r, int a, int b, ll val){
        if (b < a) return;
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
        if (b < a) return 0;
        if(a > r || b < l)return 0;
        if(a <= l && r <= b)return tree[p].val;
        int mid = (l+r)>>1;
        pushdown(p,l,mid,r);
        return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);
    }
    void init(vector<int> &a) {
        tree.resize((N+1)<<2);
        build(1,1,N,a);
    }
};

// auto it = ivals.upper_bound( {r,INF,-1} );
// vector<iv> del, add;
// while (1) {
//     if (it == begin(ivals)) break;
//     iv x = *(--it);
//     if (x[1] < l) break;
//     ll dv = lazy[x[2]];
//     int L = max(l, x[0]), R = min(r, x[1]);
//     if (x[0] < l)
//         add.push_back( {x[0], l-1, x[2]} );
//     if (x[1] > r)
//         add.push_back( {r+1, x[1], x[2]} );
//     seg.upd(dv, L, R);
//     del.push_back(x);
// }
// for (iv &x : del) ivals.erase(x);
// for (iv &x : add) ivals.insert(x);
// ivals.insert( {l,r,c} );
// seg.upd(-lazy[c], l, r);

void upd(int l, int r, int x) {
    auto it = spec.upper_bound( {r,INF} );
    vector<pi> del, add;
    while (1) {
        if (it == begin(spec)) break;
        pi p = *(--it);
        if (p[1] < l) break;
        if (x == 0) {
            del.push_back(p);
        }
        if (x == 1) {
            // // (l,r) contains p
            // if (l <= p[0] && p[1] <= r) { }
            // // p contains (l,r)
            // if (p[0] <= l && r <= p[1]) {
            //     del.push_back(p);
            //     add.push_back( {l,r} );
            //     seg.set(1, p[0], l-1);
            //     seg.set()
            // }
        }

    }
}

void upd() {
    cin >> l >> r >> x;
    if (x == 1 && l == r) seg.set(2,l,r);
    if (x == 0)
        seg.set(1,l,r),
        upd(l,r,x);
}

void qry() {
    cin >> x;
    int v = seg.query(x,x);
    if (v == 1) cout << "NO\n";
    if (v == 2) cout << "YES\n";
    if (v == 3) cout << "N/A\n";
}

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N+1, 3);
    seg.init(A);

    set<pi> spec;
    while (Q--) {
        cin >> t;
        if (t == 0) qry();
        if (t == 1) upd();
    }

}
