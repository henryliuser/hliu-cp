#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1<<20;

ll t, x;
set<int> idx;
vector<ll> A(N, -1);

void q1(ll x) {
    int i = x % N;
    if (A[i] == -1) {
        A[i] = x;
        idx.erase(i);
        return;
    }
    auto it = idx.lower_bound(i);
    if (it == end(idx)) it = begin(idx);
    A[*it] = x;
    idx.erase(it);
}

void q2(ll x) {
    int i = x % N;
    cout << A[i] << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    for (int i = 0; i < N; ++i)
        idx.insert(i);
    int Q; cin >> Q;
    while (Q--) {
        cin >> t >> x;
        if (t == 1) q1(x);
        if (t == 2) q2(x);
    }
}
