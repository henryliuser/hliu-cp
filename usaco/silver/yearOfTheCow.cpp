#include <bits/stdc++.h>
using namespace std;

int N, K;
set<int> blocks;
vector<int> gaps;

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        blocks.insert(ceil(x/12.0)*12);
    }
    int last = 0;
    int ans = *blocks.rbegin();
    while (!blocks.empty()) {
        auto it = blocks.begin();
        gaps.push_back(*it - last - 12);  // -12, we're counting the skippable gap
        last = *it;
        blocks.erase(it);
    }
    sort(rbegin(gaps), rend(gaps));
    for (int i = 0; i < K-1 && i < gaps.size(); ++i)
        ans -= gaps[i];
    cout << ans << endl;
}
