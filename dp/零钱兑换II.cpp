class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[i]表示金额为i的组合方式有多少种
        //金额为i的组合方式由两方面构成，一方面是自己本身有多少种组合方式，一方面是根据硬币的面额确定dp[i-coins]有多少种
        //所以dp[i]是由两部分加起来的，第二方面确定了是以coins[j]为基准遍历每一个面额
        
        //遍历所有硬币：
        //对于每个硬币，我们将从金额 0 遍历到 amount：
        //对于每个面额 x，计算组合数：dp[x] += dp[x - coin]。
        //返回 dp[amount]。
        vector<int> dp(amount + 1);
        int n = coins.size();
        dp[0] = 1;
        /*for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
                if(i>=coins[j])
                    dp[i]+=dp[i-coins[j]];
        }*/
        for (int i = 0;i < n;i++)
            for (int j = 1;j <= amount;j++)
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
        return dp[amount];
    }
};