// https://atcoder.jp/contests/abc237/tasks/abc237_g
// nice question. Since target is fixed, just use seg tree to
// track number of elements Less Than target in any range
// a sort query just slides all the LT elements to one side,
// if target contained, slot it in next to the LT, then the remaining
// are GT.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 2e5+5;

int N, Q, X;

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
    SegTree(vector<int> &a) {
        tree.resize(N<<2);
        build(1,1,N,a);
    }
};

int c,l,r;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = -1;
    cin >> N >> Q >> X;
    vector<int> Plt(N+1);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        Plt[i+1] = 1 + (x < X);  // ben qi's seg tree breaks
        if (x == X) t = i+1;     // on values below 1 lol
    }
    SegTree lt(Plt);
    while (Q--) {
        cin >> c >> l >> r;
        int nl = lt.query(l, r) - (r-l+1);   // hack around bad seg tree
        lt.set(1, l, r);
        bool cont = (l <= t && t <= r);
        if (c == 1) {
            lt.add(1, l, l+nl-1);
            if (cont) t = l+nl;
        }
        if (c == 2) {
            lt.add(1, r-nl+1, r);
            if (cont) t = r-nl;
        }
    }
    cout << t << '\n';

}
