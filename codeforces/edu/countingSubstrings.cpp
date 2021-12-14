#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
#define f first
#define s second

template<typename A, typename K>
void countSort(A &P, K &C) {
    int N = P.size();
    vector<int> res(N), cnt(N), pos(N);
    for(int x : C) ++cnt[x];
    for(int i = 1; i < N; ++i)
        pos[i] = pos[i-1] + cnt[i-1];
    for(int x : P) res[pos[C[x]]++] = x;
    swap(P, res);
}

template<typename FN>
void assign(FN& g, vector<int> &P, vector<int> &C) {
    int N = P.size();
    vector<int> res(N);
    res[P[0]] = 0;
    for (int i = 1; i < N; ++i) {
        int diff = ( g(i) != g(i-1) );
        res[P[i]] = res[P[i-1]] + diff;
    }
    swap(C, res);
}

vector<int> build(string &S) {
    S += "$";
    int N = S.size();
    vector<pi> A(N);
    vector<int> P(N), C(N);
    for (int i = 0; i < N; ++i) A[i] = {S[i], i};
    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i) P[i] = A[i].s;
    auto g = [&](int i) { return A[i].f; };
    assign(g, P, C);
    for (int k = 0; (1<<k) < N; ++k) {
        for (int i = 0; i < N; ++i)
            P[i] = (P[i] - (1<<k) + N) % N;
        countSort(P, C);
        auto h = [&](int i) {
            pi p = {C[P[i]], C[(P[i] + (1<<k)) % N]};
            return p;
        };
        assign(h, P, C);
    }
    return P;
}

int S;
string s;
vector<int> sfx;

short check(int g, string &s, string &q) {
    int Q = q.size();
    for (int i = 0; i < Q; ++i) {
        if (q[i] < s[i+g])
            return 0;
        if (q[i] > s[i+g])
            return 2;
    }
    if (g > S-Q) return 0;
    return 1;
}

int solve() {
    string q; cin >> q;
    // upper bound
    int lo = 0, hi = S;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        if (check(sfx[mid], s, q) == 0) hi = mid;
        else lo = mid+1;
    }
    int ub = lo;
    // lower bound
    lo = 0, hi = S;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        if (check(sfx[mid], s, q) < 2) hi = mid;
        else lo = mid+1;
    }
    return ub - lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> s >> N;
    sfx = build(s);
    S = s.size();
    while (N--)
        cout << solve() << "\n";
}
