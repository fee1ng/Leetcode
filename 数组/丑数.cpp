class Solution {
public:
    //��̬�滮��ÿһ����������ǰһ������*2/*3/*5�����ģ�����С�����˳����������
    //dp[i]��ʾ��i+1������,����¹�ʽΪmin(dp[a]*2,dp[b]*3,dp[c]*5)
    //�����������Ҳ�����൱�ںϲ�3���������С�
    //a,b,cΪ����ָ�룬��ѡ����aָ��������£���a++������ͬ��
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