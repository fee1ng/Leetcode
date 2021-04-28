class Solution {
public:
    //dp[i]表示从0-i(包括i)上的最长递增子序列的长度
    //更新公式要么是dp[i]本身，要么是前面某j位的最长递增子序列+1
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;    //到第i位的最长递增子序列长度
        for (int i = 0;i < n;i++)
        {
            dp[i] = 1;
            for (int j = 0;j < i;j++)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};