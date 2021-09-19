#include <bits/stdc++.h>
using namespace std;

int solution (int N, int K) {
    vector<int> hay(N + 1);
    for(int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        ++hay[a];
        --hay[b + 1];
    }
    hay.pop_back();
    int curr = 0;
    for(int i  = 0; i < N; ++i) {
        curr += hay[i];
        hay[i] = curr;
    }
    sort(hay.begin(), hay.end());
    return hay[N/2];
}

int main () {
    int N, K; cin >> N >> K;
    cout << solution(N, K) << endl;
}
