// Greedy + DP, 16 ms wtf
class Solution {
public:
    unordered_map<int, int> dp;
    int minDays(int n) {
        if (n <= 1) return n;
        if (dp.count(n)) return dp[n];
        dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
};

// BFS + DP, 90 ms
class Solution {
public:
    int minDays(int n) {
        int days = 0;
        queue<int> q;
        unordered_set<int> dp;
        q.push(n);
        while (!q.empty()) {
            int layer = q.size();
            for (int l = 0; l < layer; ++l) {
                int x = q.front(); q.pop();
                if (x == 0) return days;
                if (dp.count(x)) continue;
                dp.insert(x);
                if (!dp.count(x-1)) q.push(x-1);
                if (x % 2 == 0 && !dp.count(x/2)) q.push(x/2);
                if (x % 3 == 0 && !dp.count(x/3)) q.push(x/3);
            }
            ++days;
        }
        return days;
    }
};
