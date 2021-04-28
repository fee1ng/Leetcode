class Solution {
public:
    //动态规划，每一个丑数都是前一个丑数*2/*3/*5得来的，按从小到大的顺序建立丑数表
    //dp[i]表示第i+1个丑数,其更新公式为min(dp[a]*2,dp[b]*3,dp[c]*5)
    //计算丑数序列也就是相当于合并3个有序序列。
    //a,b,c为三个指针，若选择了a指向的数更新，则a++，其他同理
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1;i < n;i++)
        {
            int temp_2 = dp[a] * 2;
            int temp_3 = dp[b] * 3;
            int temp_5 = dp[c] * 5;
            dp[i] = min(min(temp_2, temp_3), temp_5);
            if (dp[i] == temp_2)
                a++;
            if (dp[i] == temp_3)
                b++;
            if (dp[i] == temp_5)
                c++;
        }
        return dp[n - 1];
    }
};