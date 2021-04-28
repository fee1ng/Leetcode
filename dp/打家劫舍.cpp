class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        //dp[i][0]表示不偷第i户
        //dp[i][1]表示偷第i户
        int res = max(dp[0][0], dp[0][1]);
        for (int i = 1;i < n;i++)
        {
            //不偷第i户，则当前值依赖于上一户结束时的最大值
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            //偷第i户，则上一户必不能偷
            dp[i][1] = dp[i - 1][0] + nums[i];
            res = max(dp[i][0], dp[i][1]);
        }
        return res;
    }
};