class Solution {
public:
    //维护一个dp table，dp[i][j]表示到当前格子的路径数
    //第一行和第一列的dp值都为1
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0)
            return -1;
        auto dp = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0;i < n;i++)
            dp[0][i] = 1;
        for (int j = 0;j < m;j++)
            dp[j][0] = 1;
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};