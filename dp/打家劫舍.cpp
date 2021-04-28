class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        //dp[i][0]��ʾ��͵��i��
        //dp[i][1]��ʾ͵��i��
        int res = max(dp[0][0], dp[0][1]);
        for (int i = 1;i < n;i++)
        {
            //��͵��i������ǰֵ��������һ������ʱ�����ֵ
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            //͵��i��������һ���ز���͵
            dp[i][1] = dp[i - 1][0] + nums[i];
            res = max(dp[i][0], dp[i][1]);
        }
        return res;
    }
};