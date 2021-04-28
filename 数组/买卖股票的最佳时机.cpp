class Solution {
public:
    //找到当前天之前的最低价格，最大利润是当前价格-最低价或之前的最大利润
    //尽力找到当前日期之前的最低价，动态更新最大利润
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   //第i天前的最低价格
        int maxRes = 0;           //当前最大利润
        for (auto price : prices)
        {
            maxRes = max(maxRes, price - minPrice);  //当前的最大利润不是当前价格-最低价就是之前的最大利润
            minPrice = min(price, minPrice);   //更新最低价格
        }
        return maxRes;
    }
};