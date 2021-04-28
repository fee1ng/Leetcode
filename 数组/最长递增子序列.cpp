class Solution {
public:
    //dp[i]��ʾ��0-i(����i)�ϵ�����������еĳ���
    //���¹�ʽҪô��dp[i]����Ҫô��ǰ��ĳjλ�������������+1
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;    //����iλ������������г���
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