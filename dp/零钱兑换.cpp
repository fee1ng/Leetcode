class Solution {
public:
    //金额为i需要多少个最少的硬币等价于寻找金额为i-coins[j]需要最少个硬币，在此基础上+1
    //假设在计算 dp(i)之前，我们已经计算出dp(0)−dp(i−1)的答案
    //所以必须保证amount从小到大依次遍历
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);    //dp[i]表示凑够i元钱最少需要几个硬币
        if (amount == 0)
            return 0;
        dp[0] = 0;
        for (int i = 1;i <= amount;i++)
            for (int j = 0;j < n;j++)
            {
                if (coins[j] <= i)
                    dp[i] = min(1 + dp[i - coins[j]], dp[i]);
            }
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};


class Solution {
public:
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1);
        return dfs(coins, amount);
    }
    //返回amout所需要的最少硬币个数
    int dfs(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount])
            return memo[amount];
        int res = INT_MAX;
        for (int i = 0;i < coins.size();i++)
        {

            int count = dfs(coins, amount - coins[i]);
            if (count == -1)
                continue;
            res = min(count + 1, res);
            memo[amount] = res;
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};