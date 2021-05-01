class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int c : coins)
            for (int z = c; z <= amount; z++)
                dp[z] = min(dp[z], dp[z-c]+1);

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
