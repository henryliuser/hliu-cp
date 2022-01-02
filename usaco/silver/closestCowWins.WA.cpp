// greedy. it doesn't work. consider following scenario:
// in [1234] -- 1,2,3 or 2,3,4. Not all the sets are disjoint, so it's wrong.
// gets 13/21
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = array<ll, 2>;

#define all(x) (x).begin(), (x).end()

int K, M, N;
priority_queue<ll> pq;

ll score() {
    ll res = 0;
    while (!pq.empty() && N--) {
        res += pq.top();
        pq.pop();
    }
    return res;
}

ll solve() {
    cin >> K >> M >> N;
    vector<pll> A(K);
    vector<ll>  B(M);
    for (pll &x : A) cin >> x[0] >> x[1];
    for (ll  &x : B) cin >> x;
    sort(all(A)), sort(all(B));

    ll curr = 0;
    int i = 0, j = K-1;
    while (i < K && A[i][0] < B[0]) curr += A[i++][1];
    pq.push(curr);
    curr = 0;
    while (i < j && A[j][0] > B[M-1]) curr += A[j--][1];
    pq.push(curr);

    if (i >= j) return score();

    // on each segment, we extend as far as we can from left X to first O
    // if the next O is beyond the boundary, start a new segment
    curr = 0;
    ll  left = *prev( lower_bound(all(B), A[i][0]) );
    ll right = *upper_bound(all(B), A[i][0]);
    ll bound = (A[i][0] - left);
    while (i <= j) {
        pll p = A[i];
        if (p[0] <= min(bound, right))
            curr += p[1];
        else {
            pq.push(curr);
            curr  = p[1];
            left  = *prev( lower_bound(all(B), p[0]) );
            right = *upper_bound(all(B), p[0]);
            bound = p[0] - left;
        }
        ++i;
    }
    pq.push(curr);
    return score();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";
}
