#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

struct BIT {
    int N;
    vector<int> bit;
    void init(int n) {
        N = n+1;
        bit.assign(n+1, 0);
    }
    void update(int i, int val) {
        for (++i; i < N; i += i & -i)
            bit[i] += val;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

int solve() {
    int N, M; cin >> N >> M;
    vector<pii> sight(N*M);
    for (int i = 0; i < N*M; ++i) {
        cin >> sight[i].f;
        sight[i].s = i;
    }
    sort(begin(sight), end(sight));
    vector<vector<pii>> arr(N, vector<pii>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            pii p = sight[i*M+j];
            arr[i][j] = {p.f, -p.s};
        }
        sort(begin(arr[i]), end(arr[i]));
    }

    vector<BIT> ft(N);
    vector<int> pos(N*M);
    for (int i = 0; i < N; ++i) {
        ft[i].init(M);
        for (int j = 0; j < M; ++j)
            pos[-arr[i][j].s] = i*M+j;
    }
    int ans = 0;
    for (int i = 0; i < N*M; ++i) {
        int r = pos[i] / M;
        int c = pos[i] % M;
        ans += ft[r].query(c);
        ft[r].update(c, 1);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
