// faster binary search
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto &Q = mp[value];
        int M = Q.size();
        if (M == 0) return 0;
        int itR = lower_bound(begin(Q), end(Q), right) - begin(Q);
        int itL = lower_bound(begin(Q), end(Q), left) - begin(Q);
        if (itR == M) --itR;
        if (Q[itR] > right) --itR;
        if (itL == M) return 0;
        return itR - itL + 1;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */


// merge tree
//
// class RangeFreqQuery {
// public:
//     struct MergeTree {
//         int N;
//         vector<int> A;
//         vector<vector<int>> T;
//         void build(int v, int tl, int tr) {
//             if (tl == tr) T[v] = {A[tl]};
//             else {
//                 int mid = (tl + tr) / 2;
//                 build(v*2, tl, mid);
//                 build(v*2+1, mid+1, tr);
//                 T[v].resize(tr-tl+1);
//                 auto &L = T[v*2], &R = T[v*2+1];
//                 merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
//             }
//         }
//         int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
//         int query(int x, int al, int ar, int v, int tl, int tr) {
//             if (tr < al || ar < tl) return 0;
//             if (al <= tl && tr <= ar)
//                 return upper_bound(begin(T[v]), end(T[v]), x) - lower_bound(begin(T[v]), end(T[v]), x);
//             int mid = (tl + tr) / 2;
//             int ql = query(x, al, ar, v*2, tl, mid);
//             int qr = query(x, al, ar, v*2+1, mid+1, tr);
//             return ql + qr;
//         }
//         void init(int n, vector<int> &v) {
//             N = n;
//             A = v;
//             T.resize(4ul*n);
//             build(1,0,N-1);
//         }
//     };
//     MergeTree seg;
//     RangeFreqQuery(vector<int>& arr) {
//         seg.init(arr.size(), arr);
//     }
//
//     int query(int left, int right, int value) {
//         return seg.query(value, left, right);
//     }
// };
// static auto _ = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// }();
//
// /**
//  * Your RangeFreqQuery object will be instantiated and called as such:
//  * RangeFreqQuery* obj = new RangeFreqQuery(arr);
//  * int param_1 = obj->query(left,right,value);
//  */
