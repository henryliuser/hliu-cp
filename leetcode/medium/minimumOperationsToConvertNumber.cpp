class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        vector<bool> seen(1001);
        q.push(start);
        int layer = 0;
        while (!q.empty()) {
            ++layer;
            int sz = q.size();
            while (sz--) {
                int x = q.front();
                q.pop();
                for (int z : nums) {
                    int ys[3] = {x+z, x-z, x^z};
                    for (int y : ys) {
                        if (y == goal) return layer;
                        if (y < 0 || y > 1000) continue;
                        if (seen[y]) continue;
                        q.push(y);
                        seen[y] = true;
                    }
                }
            }
        }
        return -1;
    }
};
