class Solution {
public:
    //只要后面的股价高于前面的股价，就进行买卖
    //即收集所有价格上坡的小区间,贪心算法
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
    //找数组中子数组的谷底，即子数组的低值
    //找数组中子数组的山峰，即子数组的高值，两项相减
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 1;
        int res = 0;
        while (i < n)
        {
            while (i < n && prices[i] <= prices[i - 1])  //寻找谷底
                i++;
            int min = prices[i - 1];    //当前子数组的最低值
            while (i < n && prices[i] >= prices[i - 1])  //寻找山峰
                i++;
            int max = prices[i - 1];    //当前子数组的山峰
            res += (max - min);
        }
        return res;
    }
};