class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = 0;
        int curr = 0;
        int res = INT_MAX;
        vector<int> dp(n + 1);
        dp[0] = n + 1;
        while (right < n)
        {
            curr += arr[right];
            if (curr > target)
            {
                while (curr > target)
                {
                    curr -= arr[left];
                    left++;
                }

            }
            if (curr == target)
            {
                int len = right - left + 1;
                res = min(res, len + dp[left]);
                dp[right + 1] = min(dp[right], len);
            }
            else
            {
                dp[right + 1] = dp[right];
            }
            right++;
        }
        if (res > n)
            return -1;
        return res;
    }
};