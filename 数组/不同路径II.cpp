class Solution {
public:
    //与前一题相同同样是动态规划，但是更新dp表时需要注意当前格子是否为障碍物
    //如果在第一行，障碍物之前的格子都为1，障碍物之后的格子都为0
    //如果在第一列，同理，障碍物之前的格子为1，之后的格子为0.需要flag变量标注当前的格子在障碍物之前或之后
    //对于中间的格子，如果当前格子为障碍物，dp[i][j]=0，如果不是,dp[i][j]=dp[i-1][j]+dp[i][j-1]
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n));
        int flag = 1;
        for (int i = 0;i < n;i++)
        {
            if (obstacleGrid[0][i] == 0 && flag)
                dp[0][i] = 1;
            else if (obstacleGrid[0][i] == 1)
            {
                flag = 0;
                dp[0][i] = 0;
            }
            else if (flag == 0)
                dp[0][i] = 0;
        }
        flag = 1;
        for (int j = 0;j < m;j++)
        {
            if (obstacleGrid[j][0] == 0 && flag)
                dp[j][0] = 1;
            else if (obstacleGrid[j][0] == 1)
            {
                flag = 0;
                dp[j][0] = 0;
            }
            else if (flag == 0)
                dp[j][0] = 0;
        }
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};