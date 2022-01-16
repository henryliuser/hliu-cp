#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    vector<int> P(N);
    for (int &x : P) cin >> x;

    priority_queue<int> pq;
    for (int i = 0; i < K-1; ++i)
        pq.push(-P[i]);
    for (int i = K-1; i < N; ++i) {
        pq.push( -P[i] );
        while (pq.size() > K)
            pq.pop();
        cout << -pq.top() << "\n";
    }
}
