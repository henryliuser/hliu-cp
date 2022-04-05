// Work in progress
struct PU_MST_Seg{
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define pb push_back
    using namespace __gnu_pbds;
    typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
            tree_order_statistics_node_update> pds;

    int n;
    vector<pds> mst;
    void init(int N) {
        n = N;
        mst.resize(N);
    }
    void build(int v, int b, int e)
    {
        if (b == e) {
            mst[v].insert( {arr[b],b} );
            return;
        }
        for (int i = b; i <= e; ++i)
            mst[v].insert( {arr[i],i} );

        int mid = (b + e) / 2;
        build(v<<1, b, mid);
        build(v<<1|1, mid+1, e);
    }
    ll query(int l, int r, int k) { return query(1,1,n,l,r,k); }
    ll query(int v, int b, int e, int l, int r, int x, int idx)

}
