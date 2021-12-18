// this solves a completely different problem lol
// given N friends with i-th friend having i dollars
// and A[i] and B[i] represent how much richer/poorer they can accept
// max invites

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

struct Interval {
    int left  = -1;
    int right = INT_MAX;
    multiset<int> Ls, Rs;
    void insert(pii &p) {
        Ls.insert(p.f);
        Rs.insert(p.s);
        left  = max(left, p.f);
        right = min(right, p.s);
    }
    void erase(pii &p) {
        Ls.erase( Ls.find(p.f) );
        Rs.erase( Rs.find(p.s) );
        left  = *Ls.rbegin();
        right = *Rs.begin();
    }
    bool ok(int i) {
        return left <= i && i <= right;
    }
};

int solve() {
    int ans = 1;
    int N; cin >> N;
    vector<pii> A(N);
    for (int i = 1; i <= N; ++i) {
        int a, b; cin >> a >> b;
        A[i-1] = {i-b, i+a};
    }
    int i = 0;
    Interval curr;
    for (int j = 0; j < N; ++j) {
        curr.insert( A[j] );
        while ( !curr.ok(j+1) )
            curr.erase( A[i++] );
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";

}

// 2 3 1 2 2 1 1 1 6 5 5 5 5 0 0 5 5 5 5 5 5
