#include <bits/stdc++.h>
using namespace std;
int N, K;
bool check(vector<int>& v, int guess) {
    guess *= 2;
    int left = v[0];
    int shots = 1;
    for (int z = 1; z < v.size(); z++) {
        int c = v[z];
        if (c-left > guess) {
            left = c;
            shots++;
        }
    }
    return shots <= K;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> N >> K;
    vector<int> cows(N);
    for (int z = 0; z < N; z++)
        cin >> cows[z];
    sort(cows.begin(), cows.end());

    int lo = 1, hi = 5e8 + 1;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        if (check(cows, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}
