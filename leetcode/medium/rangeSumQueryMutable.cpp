class NumArray {
public:
    NumArray(vector<int>& nums) : A{nums} {
        N = A.size();
        T.resize(4*N);
        build(1, 0, N-1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];
        }
    }

    void update(int i, int val) { update(i, val, 1, 0, N-1); }
    void update(int i, int val, int v, int tl, int tr) {
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];
        }
    }

    int sumRange(int l, int r) { return sumRange(l, r, 1, 0, N-1); }
    int sumRange(int l, int r, int v, int tl, int tr) {
        if (l > r) return 0;
        if (l == tl && r == tr) return T[v];
        int mid = (tl + tr) / 2;
        int ql = sumRange(l, min(r, mid), v*2, tl, mid);
        int qr = sumRange(max(l, mid+1), r, v*2+1, mid+1, tr);
        return ql + qr;
    }
private:
    int N;
    vector<int> T, &A;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
