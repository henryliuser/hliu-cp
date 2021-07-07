#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N; scanf("%d", &N);
    vector<int> nums(N);
    int ans = 0;
    for (int& n : nums) scanf("%d", &n);
    vector<int> exp;
    sort(begin(nums), end(nums));
    for (int i = 0; i < N; ++i) {
        exp.push_back(nums[i]);
        for (int j = i+1; j < N; ++j) {
            exp.push_back(nums[j] - nums[i]);
        }
    }
    sort(exp.begin(), exp.end());
    int L = exp.size();
    set<vector<int>> s;
    for (int i = 0; i < L; ++i) {
        for (int j = i+1; j < L; ++j) {
            for (int k = j+1; k < L; ++k) {
                int a = exp[i], b = exp[j], c = exp[k];
                if (s.count({a, b, c})) continue;
                s.insert({a,b,c});
                set<int> all{a, b, c, a+b, a+c, b+c, a+b+c};
                bool flag = true;
                for (int n : nums) {
                    if (!all.count(n)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) ans++;
            }
        }
    }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        printf("%d\n", solve());
    }
}
