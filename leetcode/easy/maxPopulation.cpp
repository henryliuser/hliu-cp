class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101, 0);
        for (auto& log : logs) {
            for (int z = log[0]; z < log[1]; z++) {
                years[z-1950] += 1;
            }
        }
        int ans = 0;
        for (int z = 1; z < 101; z++) {
            if (years[z] > years[ans])
                ans = z;
        }
        return ans+1950;
    }
};
