/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f[i][0] //持有股票
        //f[i][1] //处于冷冻期，不持有股票
        //f[i][2] //不处于冷冻期，不持有股票
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0][0]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        int res=max(dp[n-1][1],dp[n-1][2]);
        return res;
    }
};
// @lc code=end

