// O(N)
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101, 0);
        for (auto& log : logs) {
            years[log[0]-1950]++;
            years[log[1]-1950]--;
        }
        int curr = 0;
        for (int z = 0; z < 101; ++z) {
            curr += years[z];
            years[z] = curr;
        }
        int ans = 0;
        for (int z = 1; z < 101; z++) {
            if (years[z] > years[ans])
                ans = z;
        }
        return ans+1950;
    }
};

// O(N^2) ac because easy
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
