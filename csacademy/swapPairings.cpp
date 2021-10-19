#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n+1), bit(n+1) {}
    BIT(vector<int> &a) : BIT(a.size()) {
        for (int i = 0; i < N; ++i)
            update(i, a[i]);
    }
    void update(int i, int val) {
        for (++i; i <= N; i += i & (-i))
            bit[i] += val;
    }
    int query(int L, int R) { return query(R) - query(L-1); }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & (-i))
            res += bit[i];
        return res;
    }
};

int main() {
    long long ans = 0;
    int N; cin >> N;
    BIT bit(N);
    vector<int> nums(N);
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        idx[nums[i]].push_back(i);
    }
    for (int i = 0; i < N; ++i) {
        int x = nums[i];
        if (!idx.count(x)) continue;
        int a = idx[x][0];
        int b = idx[x][1];
        ans += b - a - bit.query(a, b) - 1;
        bit.update(idx[x][1], 1);
        idx.erase(x);
    }
    cout << ans << endl;

}
