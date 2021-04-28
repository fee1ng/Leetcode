class Solution {
public:
    //��ǰһ����ͬͬ���Ƕ�̬�滮�����Ǹ���dp��ʱ��Ҫע�⵱ǰ�����Ƿ�Ϊ�ϰ���
    //����ڵ�һ�У��ϰ���֮ǰ�ĸ��Ӷ�Ϊ1���ϰ���֮��ĸ��Ӷ�Ϊ0
    //����ڵ�һ�У�ͬ���ϰ���֮ǰ�ĸ���Ϊ1��֮��ĸ���Ϊ0.��Ҫflag������ע��ǰ�ĸ������ϰ���֮ǰ��֮��
    //�����м�ĸ��ӣ������ǰ����Ϊ�ϰ��dp[i][j]=0���������,dp[i][j]=dp[i-1][j]+dp[i][j-1]
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