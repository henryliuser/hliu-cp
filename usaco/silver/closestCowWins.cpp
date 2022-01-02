// http://usaco.org/index.php?page=viewproblem2&cpid=1158
// great question
// Nhoj cows split patches into sections
// leftmost and rightmost can be fully claimed with 1 cow
// middle ones can be definitely fully claimed with 2 cows (left+0.5, right-0.5)
// so, let's find the best we can do with 1 cow.
// run 2 pointers on each of the middle sections
// push to pq: best_of_1, sum-best_of_2
// reason being, it'll cost 1 cow to get the remainder.
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

    // divide into sections, run 2p on each segment to find max with 1 cow
    curr = 0;
    vector<pll> now;
    vector<vector<pll>> sections;
    ll  left = *prev( lower_bound(all(B), A[i][0]) );
    ll right = *upper_bound(all(B), A[i][0]);
    for (int z = i; z <= j; ++z) {
        ll x = A[z][0], y = A[z][1];
        if (left < x && x < right)
            now.push_back( {x,y} );
        else {
            sections.push_back(now);
            left  = *prev( lower_bound(all(B), x) );
            right = *upper_bound(all(B), x);
            now = { {x,y} };
        }
    }
    sections.push_back(now);
    for (auto &c : sections) {
        ll x = c[0][0];
        int S = c.size();
        ll cur = 0, res = 0, sum = 0;
        left = *prev( lower_bound(all(B), x) );
        ll bound = 2*x - left;
        for (i=j=0; j < S; ++j) {
            pll p = c[j];
            sum += p[1], cur += p[1];
            while (i<j && p[0] > bound) {
                cur -= c[i++][1];
                bound = 2*c[i][0] - left;  // set new right bound
            }
            res = max(res, cur);
        }
        pq.push(res);      // best u can do with 1 cow
        pq.push(sum-res);  // best u can do with the next one
    }
    return score();
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";
}
