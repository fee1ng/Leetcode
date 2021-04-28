class Solution {
public:
    //ֻҪ����Ĺɼ۸���ǰ��Ĺɼۣ��ͽ�������
    //���ռ����м۸����µ�С����,̰���㷨
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for (int i = 1;i < n;i++)
            if (prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        return profit;
    }
};

class Solution {
public:
    //��������������Ĺȵף���������ĵ�ֵ
    //���������������ɽ�壬��������ĸ�ֵ���������
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 1;
        int res = 0;
        while (i < n)
        {
            while (i < n && prices[i] <= prices[i - 1])  //Ѱ�ҹȵ�
                i++;
            int min = prices[i - 1];    //��ǰ����������ֵ
            while (i < n && prices[i] >= prices[i - 1])  //Ѱ��ɽ��
                i++;
            int max = prices[i - 1];    //��ǰ�������ɽ��
            res += (max - min);
        }
        return res;
    }
};