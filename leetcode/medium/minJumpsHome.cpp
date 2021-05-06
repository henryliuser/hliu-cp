class Solution {
public:

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int ans = 0;
        vector<vector<bool>> seen(2, vector<bool>(100000, false));
        // { {no-back, back} }
        unordered_set<int> forb(forbidden.begin(), forbidden.end());
        queue<pair<int, int>> q;
        seen[1][0] = true, seen[0][0] = true;
        seen[1][a] = true;
        if (x == 0) return x;
        if (!forb.count(a)) q.push( {1,a} );
        while (!q.empty()) {
            ans++;
            int len = q.size();
            while (len--) {
                auto& p = q.front();
                int d = p.first, c = p.second;
                q.pop();
                if (c == x) return ans;
                int right = c+a, left = c-b;

                if (d && left > 0 && !seen[0][left] && !forb.count(left)) {
                    seen[0][left] = true;
                    q.push( {0, left} );
                }
                if (right < 100000 && !seen[1][right] && !forb.count(right)) {
                    seen[1][right] = true;
                    q.push( {1, right} );
                }
            }
        }
        return -1;

    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
