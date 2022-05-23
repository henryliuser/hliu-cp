class Solution {
public:
    int num = 0;
    void dfs(int x, vector<vector<int>>& r, vector<bool>& seen) {
        if (seen[x]) return;
        num++;
        seen[x] = true;
        for (int& room : r[x])
            dfs(room, r, seen);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> seen(N);
        dfs(0, rooms, seen);
        return num == N;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
