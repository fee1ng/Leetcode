class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划
        //初始化第一行和第一列，第一行只能从起点向右走，即dp[0][i]=dp[0][i-1]+grid[0][i]
        //第一列只能从起点向下走，即dp[i][0]=dp[i-1][0]+grid[i][0]
        //中间部分的最小值不是从上一下向下就是从左边向右，所以有
        //dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        //return dp[m-1][n-1]
        int m=grid.size();
        int n=grid[0].size();
        auto dp = vector < vector <int> >(m, vector <int> (n));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<n;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        return dp[m-1][n-1];
    }
};