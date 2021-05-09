class Solution {
public:
    int N;
    bool dfs(int x, vector<int>& arr, vector<bool>& seen) {
        if (seen[x]) return false;
        seen[x] = true;
        int j = arr[x];
        if (j == 0) return true;
        bool back, front;
        if (x+j < N) front = dfs(x+j, arr, seen);
        if (x-j >= 0) back = dfs(x-j, arr, seen);
        return back || front;
    }

    bool canReach(vector<int>& arr, int start) {
        N = arr.size();
        vector<bool> seen(N);
        return dfs(start, arr, seen);
    }
};
