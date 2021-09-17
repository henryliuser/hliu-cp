#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> stacks(N);
    for (int i = 0; i < K; ++i) {
        int A, B; cin >> A >> B;
        stacks[--A]++;
        if (B >= N) continue;
        stacks[B]--;
    }
    int curr = 0;
    for (int i = 0; i < N; ++i) {
        curr += stacks[i];
        stacks[i] = curr;
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[N/2] << endl;
}
