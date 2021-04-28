class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[i]��ʾ���Ϊi����Ϸ�ʽ�ж�����
        //���Ϊi����Ϸ�ʽ�������湹�ɣ�һ�������Լ������ж�������Ϸ�ʽ��һ�����Ǹ���Ӳ�ҵ����ȷ��dp[i-coins]�ж�����
        //����dp[i]���������ּ������ģ��ڶ�����ȷ��������coins[j]Ϊ��׼����ÿһ�����
        
        //��������Ӳ�ң�
        //����ÿ��Ӳ�ң����ǽ��ӽ�� 0 ������ amount��
        //����ÿ����� x�������������dp[x] += dp[x - coin]��
        //���� dp[amount]��
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