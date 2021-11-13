// prefix max O(N log N + Q log N)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int N = items.size();
        sort(begin(items), end(items));
        vector<int> beauty(N), price(N), preMax;
        for (int i = 0; i < N; ++i) {
            price[i] = items[i][0];
            beauty[i] = items[i][1];
            if (i) beauty[i] = max(beauty[i], beauty[i-1]);
        }
        vector<int> ans;
        for (int q : queries) {
            int idx = upper_bound(begin(price), end(price), q) - begin(price);
            if (idx == N) -- idx;
            if (price[idx] > q) --idx;
            ans.push_back((idx < 0) ? 0 : beauty[idx]);
        }
        return ans;
    }
};


// shitty segment tree lmao
class Solution {
public:
    struct SegTree {
        int N;
        vector<int> T, &A;  // tree array, array reference
        void build(int v, int tl, int tr) {
            // v: tree index, tl/tr: tree bounds
            if (tl == tr) T[v] = A[tl];
            else {
                int mid = (tl + tr) / 2;
                build(v*2, tl, mid);
                build(v*2+1, mid+1, tr);
                T[v] = max(T[v*2], T[v*2+1]);  // adjust this
            }
        }
        int query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
        int query(int al, int ar, int v, int tl, int tr) {
            // al/ar: arr bounds
            if (al > ar) return 0;
            if (al == tl && ar == tr) return T[v];
            int mid = (tl + tr) / 2;
            int ql = query(al, min(ar, mid), v*2, tl, mid);
            int qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
            return max(ql, qr);  // adjust this
        }
        SegTree(int n, vector<int>& a)
            : N{n}, A{a}, T(4*n) {  build(1, 0, N-1); }
    };
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int N = items.size();
        sort(begin(items), end(items));
        vector<int> beauty(N), price(N);
        for (int i = 0; i < N; ++i) {
            price[i] = items[i][0];
            beauty[i] = items[i][1];
        }
        vector<int> ans;
        SegTree rmq(N, beauty);
        for (int q : queries) {
            int idx = upper_bound(begin(price), end(price), q) - begin(price);
            if (idx == N) -- idx;
            if (price[idx] > q) --idx;
            ans.push_back(rmq.query(0, idx));
        }
        return ans;
    }
};
