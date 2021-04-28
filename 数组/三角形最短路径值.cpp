class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;
        int m = triangle[0].size();
        int level = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        while (level < n)
        {
            int size = triangle[level].size();
            //当前层最左边端点的路径值只能由上一层的最左边得来
            dp[level][0] = dp[level - 1][0] + triangle[level][0];
            //当前层的最右边端点的路径值只能由上一层最后一个端点得来
            dp[level][size - 1] = dp[level - 1][size - 2] + triangle[level][size - 1];
            int i = 1;
            while (i < size - 1)
            {
                dp[level][i] = min(dp[level - 1][i], dp[level - 1][i - 1]) + triangle[level][i];
                i++;
            }
            level++;
        }
        int res = INT_MAX;
        for (int i = 0;i < triangle[n - 1].size();i++)
        {
            if (dp[n - 1][i] < res)
                res = dp[n - 1][i];
        }
        return res;
    }
};

//空间优化O(n)，从上往下动态规划
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            f[i] = f[i - 1] + triangle[i][i];
            //若从前往后更新，则当前dp[j]的值由[i,j-1]和[i-1,j]决定，不符合题意
            for (int j = i - 1; j > 0; --j)     //从后往前更新
            {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};

//空间优化O(n)，从下往上动态规划

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //从底到上动态规划，因为路径可以从上往下看也可以从下往上看
        //往上看路径，dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]
        //简化为一维滚动数组，为dp[j]=min(dp[j],dp[j+1])+triangle[i][j]
        //每一层从左往右遍历，从倒数第二层开始遍历，最后返回dp[0]
        int n = triangle.size();
        auto dp = triangle[n - 1];
        for (int i = n - 2;i >= 0;i--)
        {
            for (int j = 0;j <= i;j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        }
        return dp[0];
    }
};