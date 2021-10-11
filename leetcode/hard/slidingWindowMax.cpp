// O(N) mono-deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int N = nums.size();
        for (int i = 0; i < k; ++i) {
            int x = nums[i];
            while (!dq.empty() && x > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < N; ++i) {
            int x = nums[i];
            if (dq.front() <= i-k) dq.pop_front();
            while (!dq.empty() && x > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// O(N log N) seg tree
class Solution {
public:
    int T[(int)4e5 + 1];
    vector<int> A;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = max( T[v*2], T[v*2+1] );
        }
    }
    int query(int L, int R) { return query(L, R, 1, 0, N-1); }
    int query(int L, int R, int v, int tl, int tr) {
        if (L > R) return INT_MIN;  // important
        if (L == tl && R == tr) return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(L, min(R, mid), v*2, tl, mid);
        int qr = query(max(L, mid+1), R, v*2+1, mid+1, tr);
        return max(ql, qr);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        A = nums;
        int N = A.size();
        build(1, 0, N-1);
        vector<int> ans(N-k+1);
        for (int i = 0; i < N-k+1; ++i)
            ans[i] = query(i, i+k-1);

        return ans;
    }
};
