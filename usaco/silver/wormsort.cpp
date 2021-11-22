#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;

int N, M;
int a, b, w;
vector<int> A;
vector<tup> edges;

struct DSU {
    int count;
    vector<int> psz;
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
    DSU(int n) : count(n), psz(n, -1) {}
};

bool check(int g) {
    DSU uf(N+1);
    for (int i = g; i < M; ++i) {
        tie(w,a,b) = edges[i];
        uf.unite(a, b);
    }
    for (int i = 0; i < N; ++i) {
        if (A[i] == i+1) continue;
        if (uf.find(A[i]) != uf.find(i+1))
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> N >> M;
    A.resize(N);
    edges.resize(M);
    bool sorted = true;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i > 0 && A[i] < A[i-1])
            sorted = false;
    }
    if (sorted) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> w;
        edges[i] = {w,a,b};
    }
    sort(begin(edges), end(edges));
    int lo = 0, hi = M;
    while (lo < hi) {
        int mid = lo + ceil((hi-lo) / 2.0);
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << get<0>(edges[lo]) << endl;


}
