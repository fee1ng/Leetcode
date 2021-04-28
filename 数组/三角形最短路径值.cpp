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
            //��ǰ������߶˵��·��ֵֻ������һ�������ߵ���
            dp[level][0] = dp[level - 1][0] + triangle[level][0];
            //��ǰ������ұ߶˵��·��ֵֻ������һ�����һ���˵����
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

//�ռ��Ż�O(n)���������¶�̬�滮
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            f[i] = f[i - 1] + triangle[i][i];
            //����ǰ������£���ǰdp[j]��ֵ��[i,j-1]��[i-1,j]����������������
            for (int j = i - 1; j > 0; --j)     //�Ӻ���ǰ����
            {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};

//�ռ��Ż�O(n)���������϶�̬�滮

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //�ӵ׵��϶�̬�滮����Ϊ·�����Դ������¿�Ҳ���Դ������Ͽ�
        //���Ͽ�·����dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]
        //��Ϊһά�������飬Ϊdp[j]=min(dp[j],dp[j+1])+triangle[i][j]
        //ÿһ��������ұ������ӵ����ڶ��㿪ʼ��������󷵻�dp[0]
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