class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        //分两种情况，第一间房屋偷与不偷

        //不偷第一间，则最后一间可偷可不偷
        dp[0][0] = 0;
        int r1 = 0;
        for (int i = 1;i < n;i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
            r1 = max(dp[i][0], dp[i][1]);
        }

        //第一间偷了，则最后一间必不能偷
        dp[0][1] = nums[0];
        int r2 = nums[0];
        for (int i = 1;i < n - 1;i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
            r2 = max(dp[i][0], dp[i][1]);
        }
        return max(r1, r2);
    }
};